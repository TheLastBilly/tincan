#include <libc/stdio.h>

#include <libc/string.h>
#include <libc/stdbool.h>

static int nitoa(int value, char * str, int base, size_t size)
{
    bool is_n = false;
    if(value < 0)
    {
        value *= -1;
        is_n = true;
    }

    if(base < 0)
        base *= -1;

    if(base > 16)
        return NULL;

    size_t counter = 0;    
    do
    {
        char c = value % base;
        str[counter++] = c > 9 ? c + 87 : c + 48;
    }while((value /= base) > 0 && counter < size);

    if(is_n)
        str[counter++] = '-';
    
    strrev(str);

    return counter;
}

char * itoa(int value, char * str, int base)
{
    nitoa(value, str, base, 50);
    return str;
}

void vsnprintf(char * dest, size_t size, const char * fmt, va_list va)
{
    size-=1;

    size_t dest_count = 0;
    
    int i_tmp = 0;
    char * c_ptr_tmp = NULL;

    for(size_t i = 0; fmt[i] != '\0' && dest_count < size; i++)
    {
        if(fmt[i] == '%' && i < size -2)
        {
            char command = fmt[++i];

            switch (command)
            {
            case 'd':
                i_tmp = va_arg(va, int);
                dest_count += nitoa(i_tmp, &dest[dest_count], 10, size-dest_count);
                break;

            case 'x':
                i_tmp = va_arg(va, int);
                dest_count += nitoa(i_tmp, &dest[dest_count], 16, size-dest_count);
                break;
            
            case 'c':
                if(dest_count < size)
                {
                    dest[dest_count++] = (char)va_arg(va, char);
                }
                break;
            
            case 's':
                if(dest_count < size)
                {
                    c_ptr_tmp = (char*)va_arg(va, char*); 
                    i_tmp = strlen(c_ptr_tmp);
                    if((size_t)i_tmp > (size - dest_count))
                        i_tmp = (size - dest_count);
                    strncat(&dest[dest_count], c_ptr_tmp, i_tmp);
                    dest_count += i_tmp;
                }
                break;
                
            default:
                break;
            }
        }
        else
        {
            dest[dest_count++] = fmt[i];
        } 
    }

    dest[size] = '\0';
}

void snprintf(char * dest, size_t size, const char * fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vsnprintf(dest, size, fmt, va);
    va_end(va);
}
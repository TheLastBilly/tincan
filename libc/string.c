#include <libc/string.h>

void * memcpy(void* dest, void* src, size_t size)
{
    unsigned char * n_dest = (unsigned char *)(dest);
    unsigned char * n_src = (unsigned char *)(src);
    while(size > 0)
    {
        *(n_dest++) = *(n_src++);
        size--;
    }
    return dest;
}

void * memset(void* ptr, unsigned char value, size_t size)
{
    unsigned char * n_ptr = (unsigned char *)(ptr);
    while(size > 0)
    {
        *(n_ptr++) = value;
        size--;
    }
    return ptr;
}

void * memchr(const void * src, int c, size_t size)
{
    unsigned char * n_src = (unsigned char *)src;
    while(size > 0)
    {
        if(*(n_src++) == (unsigned char)c)
            return n_src-1;
    }
    return NULL;
}

char * strncat(char * dest, const char * src, size_t size)
{
    char * ptr = dest + strlen(dest);
    while(*(src) != '\0' && size > 0)
    {
        *(ptr++) = *(src++);
        size--;
    }
    *ptr = '\0';
    return dest;
}

void strrev(char * str)
{
    char * str_end = str + strlen(str);   
    while(str_end > str)
    {
        char b = *str;
        *str++ = *str_end;
        *str_end-- = b;
    }
}

size_t strlen(const char* str)
{
    size_t size = 0;
    while(*(str++) != '\0')
        size++;
    return size;
}
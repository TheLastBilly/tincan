#include <libc/string.h>

void * memcpy(void* dest, void* src, size_t size)
{
    void *ret = dest;
    while(size > 0)
    {
        *(unsigned char*)(dest++) = *(unsigned char*)(src++);
        size--;
    }
    return dest;
}

void * memset(void* ptr, unsigned char value, size_t size)
{
    void *ret = ptr;
    while(size > 0)
    {
        *(unsigned char *)(ptr++) = value;
        size--;
    }
    return ret;
}

void * memchr(const void * src, int c, size_t size){}
char * strncat(char * dest, const char * src, size_t size){}
void strrev(char *str){}
size_t strlen(const char* str){}
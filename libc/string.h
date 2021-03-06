#pragma once

#include <libc/stddef.h>

void * memcpy(void* dest, void* src, size_t size);
void * memset(void* ptr, unsigned char value, size_t size);
void * memchr(const void * src, int c, size_t size);
char * strncat(char * dest, const char * src, size_t size);
void strrev(char *str);
size_t strlen(const char* str);
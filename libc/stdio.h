#pragma once

#include <libc/stdarg.h>
#include <libc/stddef.h>

char * itoa(int value, char *str, int base);
void vsnprintf(char * dest, size_t size, const char * fmt, va_list va);
void snprintf(char * dest, size_t size, const char * fmt, ...);
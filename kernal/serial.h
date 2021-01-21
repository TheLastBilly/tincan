#ifndef SERIAL_H_
#define SERIAL_H_

#include <kernal/mmio.h>
#include <kernal/dev/rpi.h>
#include <kernal/delay.h>

void k_uart_init();

void k_uart_putc(unsigned char c);
void k_uart_puts(const char * str);

char k_uart_getc();

#endif
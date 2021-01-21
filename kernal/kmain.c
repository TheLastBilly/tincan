#include <kernal/serial.h>

int kmain()
{
    k_uart_init();
    k_uart_puts("Hello everyone!");   
    while (1) {
        k_uart_putc(k_uart_getc());
        k_uart_putc('\n');
    }
    return 0;
}
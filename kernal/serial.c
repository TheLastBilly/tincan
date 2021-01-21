#include <kernal/serial.h>

void k_uart_init()
{

    //Taken from https://jsandler18.github.io/tutorial/boot.html
    k_mmio_write(RPI_UART0_CR, 0x00000000);

    k_mmio_write(RPI_GPPUD, 0x00000000);
    k_delay_np(150);

    k_mmio_write(RPI_GPPUDCLK0, (1 << 14) | (1 << 15));
    k_delay_np(150);

    k_mmio_write(RPI_GPPUDCLK0, 0x00000000);

    k_mmio_write(RPI_UART0_ICR, 0x7FF);

    k_mmio_write(RPI_UART0_IBRD, 1);
    k_mmio_write(RPI_UART0_FBRD, 40);

    k_mmio_write(RPI_UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));

    k_mmio_write(RPI_UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
            (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

    k_mmio_write(RPI_UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}

void k_uart_putc(unsigned char c)
{
    while(k_mmio_read(RPI_UART0_FR) & 0x20);
    k_mmio_write(RPI_UART0_DR, c);
}
void k_uart_puts(const char * str)
{
    while(*str != '\0')
        k_uart_putc(*str++);
}

char k_uart_getc()
{
    while(k_mmio_read(RPI_UART0_FR) & 0x10);
    return k_mmio_read(RPI_UART0_DR);
}
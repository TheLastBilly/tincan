#ifndef RPI_H_
#define RPI_H_

enum
{
    RPI_GPIO_BASE       = 0x3F200000,

    RPI_GPPUD               = (RPI_GPIO_BASE + 0x94),
    RPI_GPPUDCLK0           = (RPI_GPIO_BASE + 0x98),

    //Taken from https://jsandler18.github.io/tutorial/boot.html
    RPI_UART0_BASE      = 0x3F201000, // for raspi2 & 3, 0x20201000 for raspi1

    RPI_UART0_DR        = (RPI_UART0_BASE + 0x00),
    RPI_UART0_RSRECR    = (RPI_UART0_BASE + 0x04),
    RPI_UART0_FR        = (RPI_UART0_BASE + 0x18),
    RPI_UART0_ILPR      = (RPI_UART0_BASE + 0x20),
    RPI_UART0_IBRD      = (RPI_UART0_BASE + 0x24),
    RPI_UART0_FBRD      = (RPI_UART0_BASE + 0x28),
    RPI_UART0_LCRH      = (RPI_UART0_BASE + 0x2C),
    RPI_UART0_CR        = (RPI_UART0_BASE + 0x30),
    RPI_UART0_IFLS      = (RPI_UART0_BASE + 0x34),
    RPI_UART0_IMSC      = (RPI_UART0_BASE + 0x38),
    RPI_UART0_RIS       = (RPI_UART0_BASE + 0x3C),
    RPI_UART0_MIS       = (RPI_UART0_BASE + 0x40),
    RPI_UART0_ICR       = (RPI_UART0_BASE + 0x44),
    RPI_UART0_DMACR     = (RPI_UART0_BASE + 0x48),
    RPI_UART0_ITCR      = (RPI_UART0_BASE + 0x80),
    RPI_UART0_ITIP      = (RPI_UART0_BASE + 0x84),
    RPI_UART0_ITOP      = (RPI_UART0_BASE + 0x88),
    RPI_UART0_TDR       = (RPI_UART0_BASE + 0x8C),
};

#endif
#include <kernal/serial.h>

void kmain()
{
    volatile int testing = 0x0001;
    asm("wfi");
}
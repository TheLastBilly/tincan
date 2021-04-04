#include <arch/arm/stm32/include/stm32f4xx.h>
#include <arch/arm/stm32/include/utils.h>
#include <arch/arm/stm32/include/gpio.h>

#define BOOT_VTABLE_SIZE 2

#define BRAM_START          0x20000000
#define BRAM_STACK_BEG      (1024 * 20) + BRAM_START

// Get access to linker variables
extern STM32F4_UINT32 _ldata;
extern STM32F4_UINT32 _sdata;
extern STM32F4_UINT32 _edata;
extern STM32F4_UINT32 _sbss;
extern STM32F4_UINT32 _ebss;
extern STM32F4_UINT32 _estack;

void bmain();
void kmain();

// This is to make sure, vector_table is related to the linker script's
// ".vector_table"
volatile STM32F4_UINT32 * vector_table[BOOT_VTABLE_SIZE] __attribute__((section(".vector_table"))) =
{
    (STM32F4_UINT32 *) (BRAM_STACK_BEG),
    (STM32F4_UINT32 *) bmain
};

// Entrypoint for the bootloader
void bmain()
{
    // Copy .data section into ram
    volatile STM32F4_UINT32 *src, *dest;
    stm32f4_rcc_reg* rcc = RCC_REG;
    stm32f4_gpio_reg* gpiob = GPIOB_REG;
    volatile STM32F4_UINT32 *led = &gpiob->odr;
    for(src = &_ldata, dest = &_sdata; dest < &_edata; src++, dest++) *dest = *src;

    // Clear the .bss section
    for(dest = &_sbss; dest < _ebss; dest++) *dest = 0;

    GPIO_ENABLE_PORT(GPIO_PORTB);
    GPIO_PORTB_MODE(14, GPIO_OUTPUT_MODE);
    GPIO_OUT_PORTB_PIN(14, 1);
    gpiob = GPIOB_REG;
    GPIO_OUT_PORTB_PIN(14, 0);
    gpiob = GPIOB_REG;
    GPIO_OUT_PORTB_PIN(14, 1);

    // Move on to the kernel
    kmain();

    // Got to an infitite loop
    while(1);
}
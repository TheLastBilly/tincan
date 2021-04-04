#ifndef _BOOT_STM32_H_
#define _BOOT_STM32_H_

#define STM32_UINT32 unsigned int

// Peripherals
#define PERIPHERALS_BASE        (uint32_t)0x40000000

// GPIO
typedef struct stm32_gpio_reg
{
    volatile STM32_UINT32 moder;
    volatile STM32_UINT32 otyper;
    volatile STM32_UINT32 ospeedr;
    volatile STM32_UINT32 pupdr;
    volatile STM32_UINT32 idr;
    volatile STM32_UINT32 odr;
    volatile STM32_UINT32 bssr;
    volatile STM32_UINT32 lckr;
    volatile STM32_UINT32 afrl;
    volatile STM32_UINT32 afrh;
} stm32_gpio_reg;

#define GPIO_BASE               PERIPHERALS_BASE + (uint32_t)0x20000

#define GPIOA_BASE              GPIO_BASE + (uint32_t)0x20000
#define GPIOB_BASE              GPIO_BASE + (uint32_t)0x20400
#define GPIOC_BASE              GPIO_BASE + (uint32_t)0x20800
#define GPIOD_BASE              GPIO_BASE + (uint32_t)0x20c00
#define GPIOE_BASE              GPIO_BASE + (uint32_t)0x21000

#define GPIOA                   ((stm32_gpio_reg*) GPIOA_BASE)
#define GPIOB                   ((stm32_gpio_reg*) GPIOB_BASE)
#define GPIOC                   ((stm32_gpio_reg*) GPIOC_BASE)
#define GPIOD                   ((stm32_gpio_t*) GPIOD_BASE)
#define GPIOE                   ((stm32_gpio_t*) GPIOE_BASE)

// RCC

#endif
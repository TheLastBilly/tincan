#ifndef _STM32F4_BOOT_H_
#define _STM32F4_BOOT_H_

#define STM32F4_UINT32          unsigned int
#define STM32F4_UINT8           unsigned char
#define STM32F4_BOOL            STM32F4_UINT8
#define STM32F4_REG_TYPE        volatile STM32F4_UINT32

// Peripherals
#define PERIPHERALS_BASE        ((STM32F4_UINT32)0x40000000)

// GPIO
#define GPIO_BASE               (PERIPHERALS_BASE + (STM32F4_UINT32)0x20000)
typedef struct __attribute__((__packed__)) stm32f4_gpio_reg
{
    STM32F4_REG_TYPE moder;
    STM32F4_REG_TYPE otyper;
    STM32F4_REG_TYPE ospeedr;
    STM32F4_REG_TYPE pupdr;
    STM32F4_REG_TYPE idr;
    STM32F4_REG_TYPE odr;
    STM32F4_REG_TYPE bssr;
    STM32F4_REG_TYPE lckr;
    STM32F4_REG_TYPE afrl;
    STM32F4_REG_TYPE afrh;
} stm32f4_gpio_reg;

// GPIO Base Pointers
#define GPIOA_BASE              (GPIO_BASE + (STM32F4_UINT32)0x000)
#define GPIOB_BASE              (GPIO_BASE + (STM32F4_UINT32)0x400)
#define GPIOC_BASE              (GPIO_BASE + (STM32F4_UINT32)0x800)
#define GPIOD_BASE              (GPIO_BASE + (STM32F4_UINT32)0xc00)
#define GPIOE_BASE              (GPIO_BASE + (STM32F4_UINT32)0x1000)

// GPIO Pointers
#define GPIOA_REG               ((stm32f4_gpio_reg*) GPIOA_BASE)
#define GPIOB_REG               ((stm32f4_gpio_reg*) GPIOB_BASE)
#define GPIOC_REG               ((stm32f4_gpio_reg*) GPIOC_BASE)
#define GPIOD_REG               ((stm32_gpio_t*) GPIOD_BASE)
#define GPIOE_REG               ((stm32_gpio_t*) GPIOE_BASE)

// RCC
#define RCC_BASE                (PERIPHERALS_BASE + (STM32F4_UINT32)0x23800)
typedef struct __attribute__((__packed__)) stm32f4_rcc_reg
{
    STM32F4_REG_TYPE cr;
    STM32F4_REG_TYPE pll_cfgr;
    STM32F4_REG_TYPE cfgr;
    STM32F4_REG_TYPE cir;
    STM32F4_REG_TYPE ahbrstr[3];
    STM32F4_REG_TYPE reserved1c;
    STM32F4_REG_TYPE apbrstr[2];
    STM32F4_REG_TYPE reserved28[2];
    STM32F4_REG_TYPE ahbenr[2];
    STM32F4_REG_TYPE reserved38;
    STM32F4_REG_TYPE apbenr[2];
    STM32F4_REG_TYPE reserved48[2];
    STM32F4_REG_TYPE ahblp[3];
    STM32F4_REG_TYPE reserved5c;
    STM32F4_REG_TYPE apblp[2];
    STM32F4_REG_TYPE reserve68[2];
    STM32F4_REG_TYPE bdcr;
    STM32F4_REG_TYPE csr;
    STM32F4_REG_TYPE reserve78[2];
    STM32F4_REG_TYPE sscgr;
    STM32F4_REG_TYPE plli2dcfgr;
} stm32f4_rcc_reg;
#define RCC_REG                 ((stm32f4_rcc_reg*) RCC_BASE)

#endif
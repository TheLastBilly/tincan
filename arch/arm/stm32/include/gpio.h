#ifndef _STM32F4_GPIO_H_
#define _STM32F4_GPIO_H_

#include <arch/arm/stm32/include/stm32f4xx.h>
#include <arch/arm/stm32/include/utils.h>

#define GPIO_PORTA                          0
#define GPIO_PORTB                          1
#define GPIO_PORTC                          2
#define GPIO_PORTD                          3
#define GPIO_PORTE                          4

#define GPIO_ENABLE_PORT(GPIO)              BIT_SET(RCC_REG->ahbenr[0], BIT_0 << GPIO)
#define GPIO_DISABLE_PORT(GPIO)             BIT_CLR(RCC_REG->ahbenr[0], BIT_0 << GPIO)

// Modes
#define GPIO_PORT_MODE(PORT, PIN, MODE)     BIT_SET(PORT->moder, ((STM32F4_UINT32)((MODE & 0x03) << (2 * PIN))))

#define GPIO_INPUT_MODE                     0x00
#define GPIO_OUTPUT_MODE                    0x01
#define GPIO_ANALOG_MODE                    0x03

#define GPIO_PORTA_MODE(PIN, MODE)          GPIO_PORT_MODE(GPIOA_REG, PIN, MODE)
#define GPIO_PORTB_MODE(PIN, MODE)          GPIO_PORT_MODE(GPIOB_REG, PIN, MODE)
#define GPIO_PORTC_MODE(PIN, MODE)          GPIO_PORT_MODE(GPIOC_REG, PIN, MODE)
#define GPIO_PORTD_MODE(PIN, MODE)          GPIO_PORT_MODE(GPIOD_REG, PIN, MODE)
#define GPIO_PORTE_MODE(PIN, MODE)          GPIO_PORT_MODE(GPIOE_REG, PIN, MODE)

// PIN I/O
#define GPIO_IN_PORT_DATA(PORT)             ((STM32F4_UINT32)(PORT->idr))    
#define GPIO_IN_PORT_PIN(PORT, PIN)         (STM32F4_BOOL)(((GPIO_IN_PORT_DATA(PORT) & (BIT_0 << PIN))) >> PIN)
#define GPIO_OUT_PORT_DATA(PORT, DATA)      (PORT->odr = ((STM32F4_UINT32)DATA) & 0x0000ffff)    
#define GPIO_OUT_PORT_PIN(PORT, PIN, BIT)   GPIO_OUT_PORT_DATA(PORT, ((STM32F4_UINT32)(((STM32F4_BOOL)(BIT > 0)) << PIN)))

// GPIOA
#define GPIO_IN_PORTA_DATA()                GPIO_IN_PORT_DATA(GPIOA_REG)
#define GPIO_IN_PORTA_PIN(PIN)              GPIO_IN_PORT_PIN(GPIOA_REG, PIN)
#define GPIO_OUT_PORTA_DATA(DATA)           GPIO_OUT_PORT_DATA(GPIOA_REG, DATA)
#define GPIO_OUT_PORTA_PIN(PIN, BIT)        GPIO_OUT_PORT_PIN(GPIOA_REG, PIN, BIT)

// GPIOB
#define GPIO_IN_PORTB_DATA()                GPIO_IN_PORT_DATA(GPIOB_REG)
#define GPIO_IN_PORTB_PIN(PIN)              GPIO_IN_PORT_PIN(GPIOB_REG, PIN)
#define GPIO_OUT_PORTB_DATA(DATA)           GPIO_OUT_PORT_DATA(GPIOB_REG, DATA)
#define GPIO_OUT_PORTB_PIN(PIN, BIT)        GPIO_OUT_PORT_PIN(GPIOB_REG, PIN, BIT)

// GPIOC
#define GPIO_IN_PORTC_DATA()                GPIO_IN_PORT_DATA(GPIOC_REG)
#define GPIO_IN_PORTC_PIN(PIN)              GPIO_IN_PORT_PIN(GPIOC_REG, PIN)
#define GPIO_OUT_PORTC_DATA(DATA)           GPIO_OUT_PORT_DATA(GPIOC_REG, DATA)
#define GPIO_OUT_PORTC_PIN(PIN, BIT)        GPIO_OUT_PORT_PIN(GPIOC_REG, PIN, BIT)

// GPIOD
#define GPIO_IN_PORTD_DATA()                GPIO_IN_PORT_DATA(GPIOD_REG)
#define GPIO_IN_PORTD_PIN(PIN)              GPIO_IN_PORT_PIN(GPIOD_REG, PIN)
#define GPIO_OUT_PORTD_DATA(DATA)           GPIO_OUT_PORT_DATA(GPIOD_REG, DATA)
#define GPIO_OUT_PORTD_PIN(PIN, BIT)        GPIO_OUT_PORT_PIN(GPIOD_REG, PIN, BIT)

// GPIOE
#define GPIO_IN_PORTE_DATA()                GPIO_IN_PORT_DATA(GPIOE_REG)
#define GPIO_IN_PORTE_PIN(PIN)              GPIO_IN_PORT_PIN(GPIOE_REG, PIN)
#define GPIO_OUT_PORTE_DATA(DATA)           GPIO_OUT_PORT_DATA(GPIOE_REG, DATA)
#define GPIO_OUT_PORTE_PIN(PIN, BIT)        GPIO_OUT_PORT_PIN(GPIOE_REG, PIN, BIT)

#endif
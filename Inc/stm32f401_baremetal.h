/*
 * stm32f401_baremetal.h
 *
 *  Created on: 26-Aug-2026
 *      Author: karth
 */

#ifndef STM32F401_BAREMETAL_H_
#define STM32F401_BAREMETAL_H_


#include <stdint.h>

#define reg_32(addr)	*(volatile uint32_t*)(addr)

#define RCC_BASE_ADDR  0x40023800UL
#define FLASH_INF_BASE 0x40023C00UL
#define GPIOA_BASE	   0x40020000UL
#define TIM2_BASE	   0x40000000UL
#define SYSCFG_BASE    0x40013800UL
#define EXTI_BASE	   0x40013C00UL
#define NVIC_BASE	   0xE000E100UL

#define RCC_CR		reg_32(RCC_BASE_ADDR+0x00) //offset of RCC_CR
#define RCC_PLLCFGR reg_32(RCC_BASE_ADDR+0x04) //offset of RCC_PLLCFGR
#define RCC_CFGR	reg_32(RCC_BASE_ADDR+0x08)
#define RCC_AHB1ENR reg_32(RCC_BASE_ADDR+0x30)
#define RCC_APB1ENR reg_32(RCC_BASE_ADDR+0x40)
#define RCC_APB2ENR reg_32(RCC_BASE_ADDR+0x44)

#define FLASH_ACR	reg_32(FLASH_INF_BASE+0x00)//offset of FLASH_ACR

#define GPIOA_MODER reg_32(GPIOA_BASE+0x00)
#define GPIOA_ODR   reg_32(GPIOA_BASE+0x14)
#define GPIOA_BSRR  reg_32(GPIOA_BASE+0x18)
#define GPIOA_IDR	reg_32(GPIOA_BASE+0x10)
#define GPIOA_PUPDR reg_32(GPIOA_BASE+0x0C)
#define GPIOA_AFRL  reg_32(GPIOA_BASE+0x20)


#define TIM2_CR1	reg_32(TIM2_BASE+0x00)
#define TIM2_PSC	reg_32(TIM2_BASE+0x28)
#define TIM2_ARR	reg_32(TIM2_BASE+0x2C)
#define TIM2_CNT	reg_32(TIM2_BASE+0x24)
#define TIM2_SR		reg_32(TIM2_BASE+0x10)
#define TIM2_EGR    reg_32(TIM2_BASE+0x14)
#define TIM2_DIER	reg_32(TIM2_BASE+0x0C)

#define SYSCFG_EXTICR1 reg_32(SYSCFG_BASE+0x08)

#define EXTI_FTSR	reg_32(EXTI_BASE+0x0C)
#define EXTI_IMR	reg_32(EXTI_BASE+0x00)
#define EXTI_PR		reg_32(EXTI_BASE+0x14)


#define NVIC_ISER0  reg_32(NVIC_BASE+0x00)


void SystemClock_Config(void);
//void GPIO_Init(void);

#endif /* STM32F401_BAREMETAL_H_ */

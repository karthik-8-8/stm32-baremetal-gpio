#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;

} GPIO_RegDef_t;

typedef struct{
	uint8_t pin;
	uint8_t mode;
	uint8_t pull;
	uint8_t speed;
	uint8_t output_type;
	uint8_t alternate;

}GPIO_Config_t;

// GPIO modes

#define GPIO_MODE_INPUT 0U
#define GPIO_MODE_OUTPUT 1U
#define GPIO_MODE_AF  2U
#define GPIO_MODE_ANALOG 3U

// GPIO PUPDR

#define  GPIO_NOPULL 0U
#define  GPIO_PULLUP 1U
#define  GPIO_PULLDOWN 2U

//GPIO OSPEED/ slew

#define GPIO_SPEED_LOW 0U
#define GPIO_SPEED_MEDIUM 1U
#define GPIO_SPEED_HIGH 2U
#define GPIO_SPEED_VERY_HIGH 3U


// GPIO OTYPER
#define GPIO_PUSH_PULL 0U
#define GPIO_OPEN_DRAIN 1U


#define GPIOA ((GPIO_RegDef_t*)(0x40020000UL))

void GPIO_Init(GPIO_RegDef_t *GPIOx,GPIO_Config_t *config);
void GPIO_Write(GPIO_RegDef_t *GPIOx,uint8_t pin,uint8_t value);
void GPIO_Set(GPIO_RegDef_t *GPIOx,uint8_t pin);
void GPIO_Reset(GPIO_RegDef_t *GPIOx,uint8_t pin);
uint8_t GPIO_Read(GPIO_RegDef_t *GPIOx,uint8_t pin);
void GPIO_Toggle(GPIO_RegDef_t *GPIOx,uint8_t pin);

#endif

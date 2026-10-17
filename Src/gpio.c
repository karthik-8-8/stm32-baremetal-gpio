#include "gpio.h"
#include "stm32f401_baremetal.h"
void GPIO_Init(GPIO_RegDef_t *GPIOx,GPIO_Config_t *config)
{
	 if(GPIOx==GPIOA)
	 {
		 RCC_AHB1ENR|=(1U<<0);
	 }
	 //CONFIGURE MODER
	 uint8_t position=(config->pin)*2U;

	 GPIOx->MODER=((GPIOx->MODER)&(~(3U<<position)))|(((uint32_t)config->mode)<<position);

	 GPIOx->PUPDR=((GPIOx->PUPDR)&(~(3U<<position)))|(((uint32_t)config->pull)<<position);

	 GPIOx->OTYPER=((GPIOx->OTYPER)&(~(1U<<(config->pin))))|
			 ((uint32_t)config->output_type<<config->pin);

	 GPIOx->OSPEEDR=((GPIOx->OSPEEDR)&(~(3U<<position)))|(((uint32_t)config->speed)<<position);


	 if(config->mode==GPIO_MODE_AF)
	 {
		 uint8_t position1=(2*position)%16;//should restart for AFRH(4 bits) if pin no is greater than 7
		 if(config->pin<=7)
		 {
			 GPIOx->AFRL=((GPIOx->AFRL)&(~(0xF<<position1)))|
					 (((uint32_t)config->alternate)<<position1);
		 }
		 else
		 {
			 GPIOx->AFRH=((GPIOx->AFRH)&(~(0xF<<position1)))|
					  (((uint32_t)config->alternate)<<position1);
		 }
	 }
}
void GPIO_Write(GPIO_RegDef_t *GPIOx,uint8_t pin,uint8_t value)
{
	if(value)
	{
		GPIOx->ODR|=(1U<<pin);
	}
	else
	{
		GPIOx->ODR&=~(1U<<pin);
	}

}
void GPIO_Set(GPIO_RegDef_t *GPIOx,uint8_t pin)
{
	GPIOx->BSRR=(1U<<pin);
}
void GPIO_Reset(GPIO_RegDef_t *GPIOx,uint8_t pin)
{
	GPIOx->BSRR=(1U<<(pin+16U));
}
uint8_t GPIO_Read(GPIO_RegDef_t *GPIOx,uint8_t pin)
{
	return (uint8_t)((GPIOx->IDR>>pin)& 1U);
}
void GPIO_Toggle(GPIO_RegDef_t *GPIOx,uint8_t pin)
{
	if(GPIOx->ODR & (1U<<pin))
	{
		GPIO_Reset(GPIOx,pin);
	}
	else
	{
		GPIO_Set(GPIOx,pin);
	}
}














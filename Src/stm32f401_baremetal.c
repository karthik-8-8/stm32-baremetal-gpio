#include "stm32f401_baremetal.h"

void SystemClock_Config(void)
{

RCC_CR|=(1<<16);
while(!(RCC_CR&(1<<17)))

	{
	}

FLASH_ACR=(FLASH_ACR & ~(0x0F))|(2<<0); //configuring flash interface for 2wait stage

RCC_PLLCFGR=(RCC_PLLCFGR & ~(0x03F))|(8<<0);//PLLM=8
RCC_PLLCFGR=(RCC_PLLCFGR & ~(0x7FC0))|(336<<6);//PLLN=336
RCC_PLLCFGR=(RCC_PLLCFGR & ~(3<<16))|(1<<16);//PLLP=4

RCC_PLLCFGR|=(1<<22); //HSE as PLL Source

RCC_CR|=(1<<24);
while(!(RCC_CR&(1<<25)))
	{
	}

RCC_CFGR=RCC_CFGR & ~(0xF0);//AHB PRESCALER is 1 that is PLL=SYS_CLK
RCC_CFGR=(RCC_CFGR & ~(7<<10))|(4<<10);//APB1 PRESCALER is 2-->42Mhz
RCC_CFGR=(RCC_CFGR & ~(7<<13));//APB2 PRESCALER is 1 -->84Mhz

RCC_CFGR=(RCC_CFGR & ~(3<<0))|(2<<0);
while((RCC_CFGR & (3<<2))!=(2<<2))
	{

	}
}

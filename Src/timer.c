#include "timer.h"
#include "stm32f401_baremetal.h"

static Timer_Callback_t timer_callback=0;


void TIM2_IRQHandler(void)
{

	TIM2_SR &=~(1<<0);

	if(timer_callback !=0)
	{
		timer_callback();
	}
}


void Timer_Init(void){

	RCC_APB1ENR=(RCC_APB1ENR & ~(1<<0)) | (1<<0);
	TIM2_PSC=83;
	TIM2_EGR = (1<<0);//Event generation register because PSC value updates only if any event happens
}

void Timer_InitIT(void){

	Timer_Init();
	TIM2_ARR=499999;
	TIM2_EGR = (1U<<0);//Event generation register because PSC value updates only if any event happens
	TIM2_SR &=~(1U<<0);
	TIM2_DIER|=(1U<<0);//Update interrupt enable
	NVIC_ISER0|=(1U<<28);
}
void Timer_Start(void)
{
	TIM2_CR1=(TIM2_CR1 & ~(1<<0)) | (1<<0);
}
void Timer_Stop(void)
{
	TIM2_CR1 &=~(1<<0);
}

uint32_t Timer_GetCounter(void)
{
	return TIM2_CNT;
}

void Timer_DelayMs(uint32_t ms)
{
	uint32_t START=Timer_GetCounter();
	while(Timer_GetCounter()-START<(ms*1000U))
	{
	}
}
uint8_t Timer_ElapsedMs(uint32_t start,uint32_t ms)
{
	if((Timer_GetCounter()-start)>=(ms)*1000U)
	return 1;
	else
	return 0;
}

void Timer_RegisterCallback(Timer_Callback_t callback)
{
	timer_callback=callback;
}


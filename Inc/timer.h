#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void Timer_Init(void);
void Timer_InitIT(void);
void Timer_Start(void);
void Timer_Stop(void);
uint32_t Timer_GetCounter(void);
void Timer_DelayMs(uint32_t ms);
uint8_t Timer_ElapsedMs(uint32_t start,uint32_t ms);

typedef void (*Timer_Callback_t)(void);

void Timer_RegisterCallback(Timer_Callback_t callback);




#endif

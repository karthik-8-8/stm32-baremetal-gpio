


#include <stdint.h>

#include "stm32f401_baremetal.h"
#include "gpio.h"
#include "timer.h"


void My_Timer_Callback(void)
{
	GPIO_Toggle(GPIOA,5);
}



int main(void)
{
    /* PA5 = LED */
    GPIO_Config_t led_config =
    {
        .pin = 5,
        .mode = GPIO_MODE_OUTPUT,
        .pull = GPIO_NOPULL,
        .speed = GPIO_SPEED_LOW,
        .output_type = GPIO_PUSH_PULL,
        .alternate = 0
    };

    /* PA0 = Button */
    GPIO_Config_t button_config =
    {
        .pin = 0,
        .mode = GPIO_MODE_INPUT,
        .pull = GPIO_PULLUP,
        .speed = GPIO_SPEED_LOW,
        .output_type = GPIO_PUSH_PULL,
        .alternate = 0
    };

    SystemClock_Config();
    GPIO_Init(GPIOA, &led_config);
    GPIO_Init(GPIOA, &button_config);
    GPIO_Reset(GPIOA, 5);

    Timer_InitIT();
    Timer_RegisterCallback(My_Timer_Callback);
    Timer_Start();
    while(1)
    {
    }
}















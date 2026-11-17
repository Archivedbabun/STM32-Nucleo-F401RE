// main.c

#include "stm32f4xx_hal.h"
#include "main.h"
#include<string.h>


void SystemClockConfig(void);
void Error_Handler(void);
void Timer_Init(void);
void Gpio_Init(void);

TIM_HandleTypeDef timer10;


int main(void) {
	HAL_Init();
	SystemClockConfig();
	Gpio_Init();
	Timer_Init();

	HAL_TIM_Base_Start_IT(&timer10);
	while(1){};
}

void SystemClockConfig(void) {

}

void Error_Handler(void) {
	while(1){};
}

void Timer_Init(void)
{
	__HAL_RCC_TIM10_CLK_ENABLE();
	timer10.Instance = TIM10;
	timer10.Init.Prescaler = 24;
	timer10.Init.CounterMode = TIM_COUNTERMODE_UP;
	timer10.Init.Period = 64000-1;
	timer10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_TIM_Base_Init(&timer10) != HAL_OK)
	{
		Error_Handler();
	}
}

void Gpio_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef ledGpio;
	ledGpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledGpio.Pin = GPIO_PIN_5;
	ledGpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &ledGpio);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

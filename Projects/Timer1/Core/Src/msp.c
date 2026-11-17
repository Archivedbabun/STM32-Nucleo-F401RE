// msp.c


#include "stm32f4xx_hal.h"



void HAL_MspInit(void)
{
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4); // configure the priority group
	SCB->SHCSR |= 0x7 << 16; // usg fault, mem fault and bus fault exception
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer)
{
	// enable the clock timer 10
	__HAL_RCC_TIM10_CLK_ENABLE();
	// enable the irq
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	// setup priority IRQ in NVIC
	HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 15, 0);
}

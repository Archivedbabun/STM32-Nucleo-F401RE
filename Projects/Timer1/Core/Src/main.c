// main.c

#include "stm32f4xx_hal.h"
#include "main.h"
#include<string.h>


void SystemClockConfig(void);
void Error_Handler(void);




int main(void) {
	HAL_Init();
	SystemClockConfig();

	while(1){};
}

void SystemClockConfig(void) {

}

void Error_Handler(void) {
	while(1){};
}


/*
 * 001LED_Toggle.c
 *
 *  Created on: May 13, 2023
 *      Author: Hussein Mohamed
 */

#include"../Drivers/Inc/stm32f103.h"
#include"../Drivers/Inc/Stm32F103_GPIO.h"

void delay()
{
	for(u32 i = 0; i < 500000; i++);
}
int main()
{
	GPIO_Handle_t GPIO_YELLOW;

	GPIO_YELLOW.pGPIOx = MGPIOC;

	GPIO_YELLOW.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;

	GPIO_YELLOW.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;

	GPIO_YELLOW.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;

	MCAL_GPIO_PeripheralClkControl(MGPIOC, ENABLE);

	MCAL_GPIO_Init(&GPIO_YELLOW);

	while(1)
	{
		MCAL_GPIO_ToggleOutputPin(MGPIOC, GPIO_PIN_NO_13);
		delay();
	}
	return 0;
}
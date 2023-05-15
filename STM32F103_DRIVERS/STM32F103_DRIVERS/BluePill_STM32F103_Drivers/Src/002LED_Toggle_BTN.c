/*
 * 002LED_Toggle_BTN.c
 *
 *  Created on: May 13, 2023
 *      Author: Hussein Mohamed
 */

#include"../Drivers/Inc/stm32f103.h"
#include"Stm32F103_GPIO.h"

void delay()
{
	for(u32 i = 0; i < 500000 / 2; i++);
}
int main()
{
	GPIO_Handle_t GPIO_LED, GPIO_BTN;

	GPIO_LED.pGPIOx = MGPIOA;
	GPIO_BTN.pGPIOx = MGPIOB;

	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11;

	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinMode = INPUT_MODE;

	GPIO_LED.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinConfiguration = RESET_MODE; /* INPUT_PU_PL_MODE */

	MCAL_GPIO_PeripheralClkControl(MGPIOB, ENABLE);
	MCAL_GPIO_PeripheralClkControl(MGPIOA, ENABLE);

	MCAL_GPIO_Init(&GPIO_LED);
	MCAL_GPIO_Init(&GPIO_BTN);

	while(1)
	{
		if(MCAL_GPIO_ReadInputPin(MGPIOB, GPIO_PIN_NO_11) == 0 )
		{
			delay(); /* Eliminate Debouncing */
			MCAL_GPIO_ToggleOutputPin(MGPIOA, GPIO_PIN_NO_1);
		}
	}
	return 0;
}

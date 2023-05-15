/*
 * 003_LED_Toggle_BTN_INT.c
 *
 *  Created on: May 15, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #define  ==================================*/
/*================================== #define  ==================================*/
/*================================== #define  ==================================*/
#include<string.h>
#include"../Drivers/Inc/stm32f103.h"
#include"../Drivers/Inc/Stm32F103_GPIO.h"
#include"../Drivers/Inc/Stm32F103_EXTI.h"
#include"../Drivers/Inc/Stm32F103_AFIO.h"
#include"../Drivers/Inc/Stm32F103_NVIC.h"

void delay()
{
	for(u32 i = 0; i < 500000 / 2; i++);
}
int main()
{
	/* Clock Enable */
	/*===============================================================================*/
	/* GPIOA Clock Enable */
	MCAL_GPIO_PeripheralClkControl(MGPIOA, ENABLE);
	/* GPIOB Clock Enable */
	MCAL_GPIO_PeripheralClkControl(MGPIOB, ENABLE);

	/* AFIO Clock Enable */
	AFIO_PCLK_EN();

	/*===============================================================================*/

	/* LED Configuration */
	GPIO_Handle_t GPIO_LED;

	memset(&GPIO_LED, 0, sizeof(GPIO_LED) ); /* Set All Structure Members to 0 */

	GPIO_LED.pGPIOx = MGPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = OUTPUT_10MHZ_MODE;
	GPIO_LED.GPIO_PinConfig.GPIO_PinConfiguration = GP_OUTPUT_PU_PL_MODE;
	MCAL_GPIO_Init(&GPIO_LED);

	/*===============================================================================*/

	/* BTN Configuration */
	GPIO_Handle_t GPIO_BTN;

	memset(&GPIO_BTN, 0, sizeof(GPIO_BTN) ); /* Set All Structure Members to 0 */

	GPIO_BTN.pGPIOx = MGPIOB;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinMode = INPUT_MODE;
	GPIO_BTN.GPIO_PinConfig.GPIO_PinConfiguration = RESET_MODE;
	MCAL_GPIO_Init(&GPIO_BTN);

	/*===============================================================================*/

	/* Configure the Mask Bits of The 20 Interrupt Lines (EXTI_IMR) */
	MCAL_EXTI_Enable(GPIO_PIN_NO_0);

	MCAL_EXTI_InterruptEdgeType(GPIO_PIN_NO_0, EXTI_F_EDGE);

	/* Select The Port [PA, PB, PC] */
	MCAL_AFIO_SelectPort(GPIO_PIN_NO_0, GPIOB_PORT);

	/* Enable IRQ Number */
	MCAL_NVIC_EnableInterrupt(IRQ_NO_EXTI0);

	while(1);
	return 0;
}

void EXTI0_IRQHandler(void)
{
	/* Handle The Interrupt */
	MCAL_EXTI_ClearPending(GPIO_PIN_NO_0); /* Pin 0 */
	MCAL_GPIO_ToggleOutputPin(MGPIOA, GPIO_PIN_NO_1);
}

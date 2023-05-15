/*
 * Stm32F103_NVIC.c
 *
 *  Created on: May 16, 2023
 *      Author: Hussein Mohamed
 */

/*================================== #include ==================================*/
#include"Stm32F103_NVIC.h"

/*================================= FUNC_START ================================*/

/*****************************************************************
 * @fn          - MCAL_NVIC_EnableInterrupt
 *
 * @brief       - This Function Used to Enable IRQ
 *
 * @param[in]   - IRQ Number
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void MCAL_NVIC_EnableInterrupt(u8 IRQNumber)
{
	NVIC_ISER0 |= (1 << IRQNumber); /* EXTI Line0 Interrupt is in Position 6 in IVT */
}
/*================================== FUNC_END ==================================*/

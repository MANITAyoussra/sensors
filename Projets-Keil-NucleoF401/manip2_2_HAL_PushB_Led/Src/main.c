/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"


  /* Declaration of PPP Structures */
  GPIO_InitTypeDef GPIO_InitStruct;


int main(void)
{
  /* Enable GPIO Clocks */
 ..................

  /*Configure Push Button GPIO pin : PC13 */
  GPIO_InitStruct.Pin = ...........;
  GPIO_InitStruct.Mode = .............;
  GPIO_InitStruct.Pull = .............;
  GPIO_InitStruct.Speed = .............;
  HAL_GPIO_Init(............., .............);

  /*Configure Led GPIO pin : PA5 */
   GPIO_InitStruct.Pin = ...........;
  GPIO_InitStruct.Mode = .............;
  GPIO_InitStruct.Pull = .............;
  GPIO_InitStruct.Speed = .............;
  HAL_GPIO_Init(............., .............);




  /* USER CODE BEGIN WHILE */
  while (1)	
  {
		//Read Oush Button State (0=Pressed, 1=Released)
		int EtatBouton=..................(..................);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	..................(..................);
	else //Released, Led OFF
	..................(..................);
			
	}
}
	


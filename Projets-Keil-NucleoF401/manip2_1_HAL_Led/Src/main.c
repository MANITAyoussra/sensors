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

  /*Configure Led GPIO pin : PA5 */
  GPIO_InitStruct.Pin = ...........;
  GPIO_InitStruct.Mode = .............;
  GPIO_InitStruct.Pull = .............;
  GPIO_InitStruct.Speed = .............;
  HAL_GPIO_Init(............., .............);




  /* USER CODE BEGIN WHILE */
  while (1)	
  {
	.............(............., .............);
	for (int i=0; i<0x1FFFFF;i++);			
	.............(.............);
	for (int i=0; i<0x1FFFFF;i++);			
	}
}
	


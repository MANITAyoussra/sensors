#include "stm32f4xx_hal_gpio.h"
//#include "stm32f4xx.h"


int GPIO_WritePin (GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{

	if ((GPIOx->IDR & GPIO_PIN) == 0)
		return 0;
	else
		return 1;
}

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN, uint8_t Value)
{
	if (Value==1)
		GPIOx->BSRRL=GPIO_PIN;
	else
		GPIOx->BSRRH=GPIO_PIN;
	
}
/*
void HAL_GPIO_ResetBits (GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx-> BSRR= GPIO_PIN <<16;
	
}
*/


void HAL_GPIO_Init (GPIO_TypeDef* GPIOx,  GPIO_InitTypeDef*   GPIO_InitStruct)
{
//Ajouter le code de la fonction
uint32_t mask2bits, modecfg, pullupdowncfg;
int i;
mask2bits=0;	
modecfg=0;
pullupdowncfg=0;


	
	for (i=0; i<16; i++){
		if ( (GPIO_InitStruct->Pin & (1<<i)) !=0)
		{
			mask2bits |= (3<<(2*i));
			modecfg |= (GPIO_InitStruct -> Mode) << (2*i);
			pullupdowncfg |= (GPIO_InitStruct -> Pull) << (2*i);
		}
	}
	
	GPIOx->MODER &=  ~mask2bits;
	GPIOx->MODER |=  modecfg;
	
	GPIOx->PUPDR &= ~mask2bits;
	GPIOx->PUPDR |= pullupdowncfg;	
}




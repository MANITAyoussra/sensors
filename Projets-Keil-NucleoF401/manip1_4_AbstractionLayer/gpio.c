#include <gpio.h>


int GPIO_TestPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{

	if ((GPIOx->IDR & GPIO_PIN) == 0)
		return 0;
	else
		return 1;
}

void GPIO_SetPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BSRR=GPIO_PIN;
	
}

void GPIO_ResetPin (GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx-> BSRR= GPIO_PIN <<16;
	
}



void GPIO_Init (GPIO_Typedef* GPIOx,  GPIO_Struct*   GPIO_InitStruct)
{
//Ajouter le code de la fonction
...............
..................	
	
}




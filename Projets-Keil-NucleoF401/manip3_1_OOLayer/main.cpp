//#include "stm32map.h"
#include "PinAsInput.h"
#include "PinAsOutput.h"

using namespace OOlayer;

	uint16_t EtatBouton;
	uint8_t Appui=0;
	int i;	

	PinAsInput  MyButton (PC_13);

int main ()
{	
	//Outputs Config (Led: PA5 = GPIOA, Pin5)
	
	//Enable GPIOA Clock
	RCC->AHB1ENR |=0x01;
	
	
	//Configure GPIO Pins (Led: PA5) ! MODE INPUT; NO PULL
	GPIOA ->MODER &= ~ (uint32_t)(0x3 <<10); 
	GPIOA ->MODER |= 0x1 << 10; 	
	GPIOA ->PUPDR  &= ~ (uint32_t) (0x3 <<10);
	


while (1)
	{		

		if (MyButton==Appui)
			{
				//Invert PA5 Led ( ^: XOR)
				GPIOA->ODR ^= 0x20; 
	
				for (i=0xFFFFF; i>0; i--);
			}
	}
	
}

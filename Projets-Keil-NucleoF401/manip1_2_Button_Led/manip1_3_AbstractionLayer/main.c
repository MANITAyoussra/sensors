#include <gpio.h>
#include <stdint.h>


uint8_t EtatBouton;

uint32_t x;
	
int i;
int main ()
{	
	//Activate GPIOs Clocks
 	
		*RCC_AHB1ENR  |=  0x00000005; //Activation de l'horloge du PORT A/D

	//Configure GPIO Pins (Led: PA5) ! MODE INPUT ; SPEED LOW; OUTOUT PUSH PULL; NO PULL
	
 GPIOA ->MODER &= ~ (uint32_t)(0x3 <<10); 
 GPIOA ->MODER |= 0x1 << 10; // Configuration du pin 5 / Port A	

 GPIOA ->OTYPER  &= ~ (uint32_t) (0x1 <<5);
	
 GPIOA ->OSPEEDR  &= ~ (uint32_t) (0x3 <<10);
	
 GPIOA ->PUPDR  &= ~ (uint32_t) (0x3 <<10);;
   

	// Configure GPIO pins (Push Button= PC13): MODE OUTPUT
	GPIOC ->MODER &= ~ (uint32_t)(0x3 <<26); // Configuration du pin 13 / Port C : 00

	
	
	
 while (1)
  {		
 		//Read Push Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOC,GPIO_PIN_13);
		
	if (EtatBouton==0)  //If Pressed, Led ON	

		GPIO_SetPin(GPIOA, GPIO_PIN_5);

	else //Released, Led OFF
	GPIO_ResetPin(GPIOA, GPIO_PIN_5);				
}
	}

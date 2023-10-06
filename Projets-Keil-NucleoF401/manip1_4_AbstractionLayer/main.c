#include <gpio.h>
#include <stdint.h>


uint8_t EtatBouton;

uint32_t x;
	
int i;

GPIO_Struct GPIO_InitStruct ;

int main ()
{	
	//Activate GPIOs Clocks
 	
		*RCC_AHB1ENR  |=  0x00000005; //Activation de l'horloge du PORT A/D

	//Configure GPIO Pins (Led: PA5) ! MODE INPUT ; SPEED LOW; OUTOUT PUSH PULL; NO PULL
	
//Configuration du Bouton Poussoir
GPIO_InitStruct.GPIO_PIN = GPIO_PIN_13 ;
GPIO_InitStruct.GPIO_Mode = GPIO_Mode_INPUT ;
GPIO_InitStruct.GPIO_PullPush = GPIO_PullPush_NoPull;
	
GPIO_Init (GPIOC, &GPIO_InitStruct) ;

	//Configurartion de(s) Led(s)
GPIO_InitStruct.GPIO_PIN = GPIO_PIN_5;
GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUTPUT;
GPIO_InitStruct.GPIO_PullPush = GPIO_PullPush_NoPull;

	GPIO_Init (GPIOA, &GPIO_InitStruct) ;


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

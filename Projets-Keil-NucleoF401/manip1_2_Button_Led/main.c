#include <stdint.h>

#define   RCC_AHB1ENR     (uint32_t*) 0x40023830

//GPIOA REGISTERS (Led)
#define   GPIOA_MODER	  (uint32_t*) 0x40020000
#define   GPIOA_OTYPER	  (uint32_t*) 0x40020004
#define   GPIOA_OSPEEDR	  (uint32_t*) 0x40020008
#define   GPIOA_PUPDR	  (uint32_t*) 0x4002000C
#define   GPIOA_BSRR	  (uint32_t*) 0x40020018

//GPIOC REGISTERS (push button)
#define GPIOC_MODER (uint32_t*) 0x40020800
#define GPIOC_PUPDR (uint32_t*) 0x4002080C
#define GPIOC_IDR (uint32_t*) 0x400200810
//int i=4 ;


int main ()
{
// int i;
	
	//Activate GPIOs Clocks
    *RCC_AHB1ENR |= 0x0000 0005;

	//Configure GPIO Pins (Led)
    //Pin PA5 Config
    *GPIOA_MODER &= 0xFFFF F3FF;
    *GPIOA_MODER |= 0x0000 0400;
    *GPIOA_PUPDR &= 0xFFFF F3FF;
    *GPIOA_OTYPER &= 0xFFFF FFDF;
    *GPIOA_OSPEEDR &= 0xF3FF FFFF;
	// Configure GPIO pins (Push Button)
    //Pin PC13 Config
    *GPIOC_MODER &= 0xF7FF FFFF;
    *GPIOC_MODER |= 0x0800 0000 ;
    *GPIOC_PUPDR &= 0xF3FF FFFF;
    
 while (1)
  {
	 {
	 *GPIOA_BSRR = ox1<<5; // led on
	  for(i=0xffFFF; i != 0; i--); // Delay
	 *GPIOA_BSRR = ox1<<21; //led off;
	  for(i=0xFffFF; i != 0; i--); // Delay
	   }
	 
	  /Test Push Button state
	  PB_State = *GPIOA_IDR & (1<<13);
	  if (PB_State !=0)
	  GPIOC_BSRR = 1<<5; 
	   {  *GPIOA_BSRR = ox1<<5;
	    for(i=0xffFFF; i != 0; i--);}
	  else 
	   { *GPIOA_BSRR = ox1<<21;
	     for(i=0xFffFF; i != 0; i--);}
	 
	  }
		
	}		
		
}
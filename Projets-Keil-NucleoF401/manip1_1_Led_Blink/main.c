#include <stdint.h>

//RCC Register 
#define   RCC_AHB1ENR     (uint32_t*) 0x 0x4002 3830

//GPIOA REGISTERS (Led)
#define   GPIOA_MODER	  (uint32_t*) 0x40020000 
#define   GPIOA_OTYPER	  (uint32_t*) 0x40020004 
#define   GPIOA_OSPEEDR	  (uint32_t*) 0x40020008 
#define   GPIOA_PUPDR	  (uint32_t*) 0x4002000C 
#define   GPIOA_BSRR	  (uint32_t*) 0x40020018



main ()
{
 int i;
 
 *RCC_AHB1ENR  |= 0x0000 0001; //Activation de l'horloge du PORT A
 //Pin PA5 Config
 *GPIOA_MODER &= 0xFFFFF3FF;
 *GPIOA_MODER |= 0x00000400;
 *GPIOA_PUPDR &= 0xFFFFF3FF;
 *GPIOA_OTYPER &= 0xFFFFFFDF;
 *GPIOA_OSPEEDR &= 0xF3FFFFFF;
   

 
 for(i=0xFFFFF; i != 0; i--); // Delay

     
 while (1)
  {
 *GPIOA_BSRR = ox1<<5; // led on
  for(i=0xffFFF; i != 0; i--); // Delay
 *GPIOA_BSRR = ox1<<21; //led off;
  for(i=0xFffFF; i != 0; i--); // Delay
   }
}
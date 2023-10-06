#include <stdint.h>

//This File should contain Periph Base Addresses, Structures, Pointers on Structures, Pins, etc...
#define   RCC_AHB1ENR     (uint32_t*) 0x40023830

//GPIOA REGISTERS
#define   GPIOA_BASE	  0x40020000
#define   GPIOB_BASE	  0x40020400
#define   GPIOC_BASE	  0x40020800
#define   GPIOD_BASE	  0x40020C00


	typedef struct{
		uint32_t MODER;
		uint32_t OTYPER;
		uint32_t OSPEEDR;
		uint32_t PUPDR;
		volatile uint32_t IDR;
		uint32_t ODR;
		uint32_t BSRR;
		} 
	GPIO_Typedef;


//define Pointers to GPIO Strcutures 
	
#define GPIOA  ((GPIO_Typedef*) GPIOA_BASE)
#define GPIOB  ((GPIO_Typedef*) GPIOB_BASE)
#define GPIOC  ((GPIO_Typedef*) GPIOC_BASE)
#define GPIOD  ((GPIO_Typedef*) GPIOD_BASE)






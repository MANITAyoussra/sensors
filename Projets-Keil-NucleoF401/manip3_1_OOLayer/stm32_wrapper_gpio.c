/* ***************************************************************************/
/* WRAPPER LAYER : ADAPT OO Pin REPRESENTATION (mbed) TO ST Firmware Libraray*/
/* OO Representation : PA_0 = 0x01, PA_1=0x01, ...., PA_15=0x0F              */
/*                   : PB_0 = 0x11, PB_1=0x11, ...., PB_15=0x1F              */
/*																																           */
/* OO --> ST Firmware  : PA_0 --> GPIOA, GPIO_Pin_0 							           */
/*											 PB_12 --> GPIOB, GPIO_Pin_12							           */
/* Emir DAMERGI  -  INSAT 2020                                               */

/* ***************************************************************************/
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx.h"
#include "stm32_wrapper_gpio.h"


/*=====================================*/
/* 					Structures								*/
/*=====================================*/
GPIO_InitTypeDef GPIO_InitStruct;
GPIO_TypeDef* GPIOx;


	
/*=====================================================*/
	/* Common Function : To get GPIOx From PinName Value */
/*=====================================================*/
	
static GPIO_TypeDef* get_gpio_port (PinName pin)
{
	int gpioID = (pin & 0xF0) >> 4; 
		
	GPIO_TypeDef* GPIOx;
	
	switch (gpioID){
		case 0x00: GPIOx=GPIOA; break;
		case 0x01: GPIOx=GPIOB; break;
		case 0x02: GPIOx=GPIOC; break;
		case 0x03: GPIOx=GPIOD; break;
		default: break;
		}
	return GPIOx;
}



/*================================================*/
/*     Part 1: Functions For PinAsInput Class     */
/*================================================*/


/*=== Functions Called by The PinAsInput Constructors ===*/

/*Constructor Without Mode = Default = Floating*/
void gpio_init_in_def(PinName pin) 
{
    gpio_init_in (pin, InDefault);
}

/*Constructor With Mode */
void gpio_init_in (PinName pin, PinInMode mode)
{
    _gpio_init_in(pin, mode);
}


/*--------------------------------------------------------------*/
/*   INITIALLIZATION FUNCTION for PinAsInput Objects :          */          
/*      - Translates OO Pin Represetation (Px_i) to ST FWL      */
/*      - And Calls ST FWLibrary Functions                      */
/*--------------------------------------------------------------*/

static void _gpio_init_in(PinName pin, PinInMode mode)
{
		//get the gpioID from PinName (0 for GPIOA, 1 for GPIOB, ...) 	
		int gpioID = (pin & 0xF0) >> 4; 
	
		//Enable Clock
		RCC->AHB1ENR |= (1 << gpioID);
	
	  //convert gpioID to GPIOx
		GPIOx = get_gpio_port(pin);

	
		//Convert the PinName to HAL GPIO_PIN
		int gpioPIN = 1<<(pin & 0x0F);
		
 	  //Fills GPIO Structure (Pin, Mode and Pull : AF not considered)
		GPIO_InitStruct.Pin = gpioPIN;
	
		switch (mode){
		
		case 0: GPIO_InitStruct.Mode = GPIO_MODE_INPUT; //0 :Floating;
						GPIO_InitStruct.Pull = GPIO_NOPULL; 
						break;

		case 1: GPIO_InitStruct.Mode = GPIO_MODE_INPUT;	//1 :PullUp;
						GPIO_InitStruct.Pull = GPIO_PULLUP;
						break;		
		
		case 2: GPIO_InitStruct.Mode = GPIO_MODE_INPUT; //2 :PullDown;
						GPIO_InitStruct.Pull = GPIO_PULLDOWN;
						break;	
		
			case 3: GPIO_InitStruct.Mode = GPIO_MODE_ANALOG; //3: InAnalog
						GPIO_InitStruct.Pull = GPIO_NOPULL;
						break;	
	
		default: break; 
		}
	
	//	and Calls GPIO_Init (ST FW Lib)
		HAL_GPIO_Init( GPIOx,  &GPIO_InitStruct);		
	}

	
	
/*=== Function To read Pin Value from IDR ====== */
	int gpio_read(PinName pin)
{
	int pinID = (pin & 0x0F);
	uint16_t valPin= (get_gpio_port(pin)->IDR) & (1<<pinID);
	if (valPin==0) 
		return 0;
	else
		return 1;
}

/*=========== End PinAsInput Class Functions =============*/


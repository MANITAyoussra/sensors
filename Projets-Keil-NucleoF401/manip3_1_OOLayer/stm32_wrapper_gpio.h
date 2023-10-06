//#include "stm32f401xe.h"
#include "stm32map.h"
#include "stm32f4xx_hal_gpio.h"

#include "Pin_Mode_Names.h"

#ifndef __STM32_WRAPPER_GPIO_H
#define __STM32_WRAPPER_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* =======================================*/
/* 1 : Functions For PinAsInput Class --- */
/*----------------------------------------*/
	
void gpio_init_in_def(PinName pin);	
	
void gpio_init_in(PinName pin, PinInMode mode);

static void _gpio_init_in(PinName pin, PinInMode mode );

int gpio_read (PinName thepin);	
	
void get_gpio_in_mode (PinInMode mode);	
/*==========================================*/

	
/*=============================================*/
/* --- 2 : Functions For xxPinAsOutput Class --*/
/*---------------------------------------------*/
void xxgpio_init_out_def(PinName pin);
	
void xxgpio_init_out (PinName pin, PinOutMode mode);
	
void xxgpio_init_out_ex (PinName pin, PinOutMode mode, PinSpeed speed);
	
static void xx_gpio_init_out(PinName pin, PinOutMode mode, PinSpeed speed);

void xxgpio_write(PinName pin, int value);

int xxgpio_read_out(PinName pin);

static int xxget_gpio_out_mode (PinOutMode mode);	
static int xxget_gpio_out_speed (PinSpeed speed);



/* --- 3 : Common Functions ---- */

/*  Get the GPIOx From PinName  */
static GPIO_TypeDef* get_gpio_port (PinName pin);
	


#ifdef __cplusplus
}
#endif


#endif //__STM32_WRAPPER_GPIO_H

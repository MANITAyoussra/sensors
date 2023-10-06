//#include <stm32map.h>
#include <stdint.h>
#include "stm32f4xx.h"


#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

// 1- The Strcuture containing config parameters

typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
  uint32_t Alternate;  
}
GPIO_InitTypeDef;


//2 - Define The Mode parameters Values					
#define  GPIO_MODE_INPUT  0x00   
#define  GPIO_MODE_OUTPUT_PP 0x01
#define  GPIO_MODE_OUTPUT_OD 0x11
#define  GPIO_MODE_ANALOG 0x03              


#define  GPIO_SPEED_FREQ_LOW    0x00
#define  GPIO_SPEED_FREQ_MEDIUM 0x01
#define  GPIO_SPEED_FREQ_HIGH   0x02
#define  GPIO_SPEED_FREQ_VERY_HIGH 0x03

#define  GPIO_NOPULL  0x00
#define  GPIO_PULLUP  0x01
#define  GPIO_PULLDOWN  0x02
							
							

//2 bis: GPIO PINS Values
//Define GPIO_Typedef strcuture containing The GPIO Registers

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected */


//3- Functions Proyotypes

int HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
int HAL_GPIO_ReadOutPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN, uint8_t Value);

//void HAL_GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
//void HAL_GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

void HAL_GPIO_Init (GPIO_TypeDef* GPIOx,  GPIO_InitTypeDef*   GPIO_InitStruct);

#ifdef __cplusplus
}
#endif


#endif //__GPIO_H

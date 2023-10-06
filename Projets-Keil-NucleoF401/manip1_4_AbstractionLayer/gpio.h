#include <stm32map.h>



1// The Strcuture containing config parameters
typedef struct{
.........
........
..........	
}GPIO_Struct;


//2 - Define The Mode parameters Values
#define ......................
............



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

int GPIO_TestPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_ResetPin (GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_Init (GPIO_Typedef* GPIOx,  GPIO_Struct*   GPIO_InitStruct);


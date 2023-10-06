#include <stm32map.h>


//Functions Proyotypes

int GPIO_TestPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_ResetPin (GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
//void GPIO_Init (GPIO_Typedef* GPIOx,  GPIO_Struct*   GPIO_InitStruct);

//GPIO PIN VALUES
#define GPIO_PIN_0                 ((uint16_t)0x0001) 	
#define GPIO_PIN_1                 ...................
...............
.................
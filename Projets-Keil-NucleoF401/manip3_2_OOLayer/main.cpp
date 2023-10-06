#include "PinAsInput.h"
#include "PinAsOutput.h"

using namespace OOlayer;

	
	int i;	

	PinAsInput  MyButton (PC_13);
	
	PinAsOutput MyLed (PA_5);


int main ()
{	
	
	

while (1)
	{		

		if (MyButton==0)
			{
				MyLed = !MyLed;
	
				for (i=0xFFFFF; i>0; i--);
			}
	}
	
}

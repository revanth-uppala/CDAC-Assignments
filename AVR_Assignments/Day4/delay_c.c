// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

// Define here the global static variables
//
int My_global;

// Interrupt handler example for INT0
//
SIGNAL(SIG_INTERRUPT0) {

}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void delay_1ms(void);
void delay_1ms(void)
{

 TCNT1 = (255-125);
 TCCR1B= (1<<CS10);

 while(TOV1 == 1);
 TIFR = (1<< TOV1);
 TCNT1 = (255 - 125);

}

// ***********************************************************
// Main program
//
int main(void) {

DDRD = 255;

   while(1) {             // Infinite loop; define here the
       PORTD = 0xA0;
      for(int i = 0 ; i <10; i ++)
		{	
			delay_1ms();
		}
       PORTD = 0x50;    // system behaviour
   }

}




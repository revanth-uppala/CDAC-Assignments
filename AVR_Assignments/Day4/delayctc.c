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
int flag = 0;
// Interrupt handler example for INT0
//
SIGNAL(SIG_INTERRUPT0) {

}

// It is recommended to use this coding style to
ISR(TIMER2_COMP_vect)
{
    flag = !flag;
}

int main(void) {
 DDRD = 0xF0;   //PortD higher nibble as output
 TCNT2 = 0;
 OCR2 = 61;   //compare value for 1sec
 TIMSK  = TIMSK |  (1<<OCIE2);//enable Timer2 OC interrupt
 TCCR2  = TCCR2 | (1<< CS21)| (1 << WGM21);

 sei();

   while(1) {             // Infinite loop; define here the
      PORTD = 0x00;
		if(flag ==1)

     {
      	PORTD = 0xFF;
		}       // system behaviour
   }

}





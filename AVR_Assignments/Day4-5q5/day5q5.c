// ***********************************************************
/* Project:   Write a code to generate square wave at the output of pin OC1A of frequency f1 and
exactly f1/2 at OC1B */
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

// Define here the global static variables
//


// Interrupt handler example for INT0
//


ISR(TIMER1_COMPB_vect )
{
		if(OCR1B == 31250)
		{
			OCR1B= 15625;
		}
		else
		{
			OCR1B = 31250;
		}

}




// ***********************************************************
// Main program
//
int main(void) {
   DDRB |= (1<<PB1)|(1<<PB2);
	TCNT1 = 0;
   OCR1A =  31250;    //1s
  OCR1B = 15625; //2s
   TIMSK |= (1<<OCIE1B);
   TCCR1A = (1<< COM1A0)|(1<<COM1B0);
	TCCR1B = (1<<CS11)|(1<<CS10)|(1<<WGM12);
	MCUCR |= (1<<SE);
	sei();
   while(1) {             // Infinite loop; define here the
           asm("SLEEP"); // system behaviour
   }

}












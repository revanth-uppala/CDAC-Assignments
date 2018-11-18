// ***********************************************************
// Project : Design & Write a code to generate Maximum delay using Timer/Counter1:
// Author:Souvik
// Module description: gives approx 67 secs delay
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

// Define here the global static variables
//
int flag = 0;
ISR(TIMER1_OVF_vect )
{
 	flag = 1;
}

// Interrupt handler example for INT0
//

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//


// ***********************************************************
// Main program
//
int main(void) {
   DDRB = (1<<PB0);

	 TIMSK |= (1<< TOIE1);
   TCNT1= 0;
   TCCR1B |= (1<<CS10)|(1<<CS12);
   sei();
   while(1) {             // Infinite loop; define here the
     if(flag ==1)
     {
     	flag = 0;
     	PORTB = !PORTB;
     	}      // system behaviour
   }

}



// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define BV(x)  (1<<x)
#define BC(x) (0<<x)
// Define here the global static variables
//
int My_global;

// Interrupt handler example for INT0
//
ISR(        INT0_vect )
{
	PORTD ^= (1<<PD4);

}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//


// ***********************************************************
// Main program
//
int main(void) {
 	MCUCR |= BV(SE)| BV(ISC01);//enable sleep and falling edge
 	DDRD |= BV(PD4)| BC(PD2); //PD4 output,PD2input
 	PORTD |= BV(PD2); //pullup PD2	
	GICR |= BV(INT0);  //INT0 enable
	sei();

	
   while(1) {             // Infinite loop; define here the
     asm("sleep");      // system behaviour
   }

}





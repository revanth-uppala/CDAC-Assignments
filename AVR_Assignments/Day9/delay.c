// ***********************************************************
// Project : Design & Write a code to generate Maximum delay using Timer/Counter1:
// Author:Souvik
// Module description: gives approx 67 secs delay
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define CPU_FREQUENCY 1000000
// Define here the global static variables
//
int flag = 0;
void delay(int);

// Interrupt handler example for INT0
//

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//


// ***********************************************************
// Main program
//
void delay(int x)
 {
   long int cycles = (x*CPU_FREQUENCY)/65535;
	TCNT1 = 65535 - cycles;
   TCCR1B |= (1<<CS10)|(1<<CS12);
   while( TOV1 == 1);
   TIFR |= (1<<TOV1);
}
int main(void)
{
	DDRB |= (1<<PB0);
	while(1)
	{
		PORTB ^= (1<<PB0);
		delay(2);
	}
}
		






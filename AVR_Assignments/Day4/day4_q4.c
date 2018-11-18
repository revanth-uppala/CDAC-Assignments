// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define PIN_SET(PORT,PIN) PORT |= (1<<PIN)
#define PIN_CLEAR(PORT,PIN) PORT &= ~(1<<PIN)

// Define here the global static variables
//
int My_global;

// Interrupt handler example for INT0
//


// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void my_function(void) {  // Put the open brace '{' here

   asm("nop");          // Inline assembly example
}

// ***********************************************************
// Main program
//
int main(void) {

	PIN_SET(DDRB,PB3); //OC2 as output
	PIN_SET(TCCR2,WGM20);             //phase correct PWM
	PIN_SET(TCCR2,COM20);
	PIN_SET(TCCR2,COM21);
	TCNT2 = 0;
	OCR2 = 200;
	PIN_SET(TCCR2,CS20);
while(1) {             // Infinite loop; define here the
            // system behaviour
   }

}


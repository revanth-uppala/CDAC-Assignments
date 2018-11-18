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


// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
ISR(EE_RDY_vect)
{
	EEAR = 0X001;
	EEDR = 0x01;
	EECR |= (1<<EEMWE) ;
//	EECR &= ~(1<<EEWE);
//	asm("nop");
	EECR |= (1<<EEWE);
	
}
                                             // Put the open brace '{' here

   //asm("nop");                               // Inline assembly example


// ***********************************************************
// Main program
//
int main(void) {

   // while(! (EECR &(1<<EEWE) ));
   // int x;
    EECR=(1<<EERIE);
    sei();
	 while(1)
	 {
	 //	EEAR = 0x01;
	 	//EECR |= (1<< EERE);
	 //	x = EEDR;
	 //	EECR &= ~(1<<EEWE);
	 }

 /*  while(1) {             // Infinite loop; define here the
      my_function();      // system behaviour
   }*/

}





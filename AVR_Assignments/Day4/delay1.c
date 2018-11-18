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

// ***********************************************************
// Main program
//
int main(void) {
   DDRD = 0xFF;
   TCNT2 = 0x00;

   while(1) {             // Infinite loop; define here the
      my_function();      // system behaviour
   }

}


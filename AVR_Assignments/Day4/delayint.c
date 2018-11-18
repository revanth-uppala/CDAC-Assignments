// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define PIN_SET(PORT,PIN)  PORT |=    (1<<PIN)
#define PIN_CLEAR(PORT,PIN) PORT &= ~(1<<PIN)
//#define PIN_SET1(PORT,PIN1,PIN2) PORT |= (1<<PIN1)|(1<<PIN2)
//#define PIN_CLEAR1(PORT,PIN1,PIN2) PORT &= ~(1<<PIN1) | ~(1<<PIN2)
// Define here the global static variables
//
int My_global;
int flag = 0;
// Interrupt handler example for INT0
//


// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//


// ***********************************************************
// Main program
//
ISR(TIMER2_COMP_vect)
{
    flag = !flag;
}

int main(void) {
 //DDRD = 0xF0;
PIN_SET(DDRD,PD5);
PIN_SET(DDRD,PD6);
PIN_CLEAR(PORTD,PD5);
PIN_CLEAR(PORTD,PD6);
TCNT2 = 0;
 OCR2 = 61;
 TIMSK  = TIMSK |  (1<<OCIE2);
 TCCR2  = TCCR2 | (1<< CS21)| (1 << WGM21);

 sei();

   while(1) {             // Infinite loop; define here the
      PIN_SET(PORTD,PD5);
      PIN_CLEAR(PORTD,PD6);

		if(flag ==1)
     {
      	PIN_CLEAR(PORTD,PD5);
      	PIN_SET(PORTD,PD6);
 		}       // system behaviour
   }

}





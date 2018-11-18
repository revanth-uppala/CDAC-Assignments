// ***********************************************************
/*Project:     1. Write a assembly code to receive data from UART & transmit it back by adding one to it.
a. Baud Rate = 9600
b. 8 bit data
c. Single Stop Bit
*/
// Author: Souvik
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define BAUD 4800
#define F_CPU 1000000
#include <util/setbaud.h>
// Define here the global static variables
//

#define BV(X)  (1<<X)
#define BC(X)  (0<<X)
void TX(int);
int flag= 0;
int x;

ISR(  USART_RXC_vect)
{
	x = (unsigned char) UDR;
	flag = 1;
}


// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void init(void)
{

	UBRRH = UBRRH_VALUE;
   UBRRL = UBRRL_VALUE;
  	UCSRB |= BV(RXEN) | BV(TXEN) | BV(RXCIE);
	UCSRC |=  BV(URSEL) | BV(UCSZ0) | BV(UCSZ1);
	
	
}
void TX(int x)
{
   while ( !( UCSRA & (1<<UDRE)) );
	UDR = x;
		
}

// ***********************************************************
// Main program
//
int main(void)
 {
		 init();
		sei();
		TX('?');
   while(1)
    {
   			if(flag ==1)
   			{
   				flag = 0;
   				TX(++x);
   			}
   			
   			
   }

}









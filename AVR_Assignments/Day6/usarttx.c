// ***********************************************************
/*Project:     1. Write a assembly code to receive data from UART & transmit it back by adding one to it.
a. Baud Rate = 9600
b. 8 bit data
c. Single Stop Bit
*/
// Author:
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
int flag = 0;
#define BV(X) ( 1<<X)
#define BC(X) (0<<X )
void TX(unsigned char) ;
//void delay_init(void);
/*ISR(TIMER2_COMP_vect)
{
    flag = 1;
}




void delay_init(void)
{

	
 TCNT2 = 0;
 OCR2 = 61;
 TIMSK  = TIMSK |  (1<<OCIE2);
 TCCR2  = TCCR2 | (1<< CS21)| (1 << WGM21);

} */

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void init(void)
{

   UBRRH = UBRRH_VALUE;
   UBRRL = UBRRL_VALUE;
	UCSRB = BV(TXEN) ;
	UCSRC =  BV(URSEL) | BV(UCSZ0) | BV(UCSZ1);
		
}
void TX(unsigned char x)
{
   while ( !( UCSRA & (1<<UDRE)) );
	UDR = x;
		
}

// ***********************************************************
// Main program
//
int main(void) {
		 init();
	  unsigned  char str[20]  = "Hello CDAC!";
   	 int i= 0;
//	delay_init();
//	sei();
	while(1)
    {
   	
//   	if(flag == 1)
  // 	{
   //		flag = 0;
   		if(str[i] != '\0')
   		{
   			TX(str[i++]);
   		}
   		if(i >10)
   		{
   			i = 0;
   		}
  	//	 }			

   			
   }

}
















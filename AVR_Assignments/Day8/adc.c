// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define BAUD 9600
#define F_CPU 1000000
#include <util/setbaud.h>
#define BV(X) (1<<X)
#define BC(X)  ~(1<<X)
#define VREF 2.56
// Define here the global static variables
//
int x,y,flag = 0;
void TX(int);
// Interrupt handler example for INT0
//
ISR(   ADC_vect )
{
	x = ADCL;
	y = ADCH;
	flag = 1;
}	

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//


void ADC_init(void)
{
	ADMUX |= BV(REFS0) | BV(REFS1);
	ADCSRA |= BV(ADEN) |  BV(ADIE) | BV(ADPS1) | BV(ADPS0);
	ADCSRA |= BV(ADSC); //start conversion
}
void USART_init(void)
{

   UBRRH = UBRRH_VALUE;
   UBRRL = UBRRL_VALUE;
	UCSRB = BV(TXEN) ;
	UCSRC =  BV(URSEL) | BV(UCSZ0) | BV(UCSZ1);
	
}
void TX(int x)
{
   while ( !( UCSRA & (1<<UDRE)) );
	UDR = x;		
}


// ***********************************************************
// Main program
//
int main(void) {
DDRB  |= BC(PB0); //PB0 as input
PORTB |= BV(PB0); //pullup
USART_init();
sei();
ADC_init();
while(1)
{
	if(flag == 1)
	{
		flag = 0;
		TX(x);
		
		asm("nop");
		ADCSRA |= BV(ADSC); //start conversion
	}

}

}











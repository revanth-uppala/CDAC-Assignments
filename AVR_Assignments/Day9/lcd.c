// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define RS PC0
#define RW PC1
#define EN PC2
#define LCDport PORTB
#define PIN_SET(PORT,PIN) PORT |= (1<<PIN)
#define PIN_CLEAR(PORT,PIN) PORT &= ~(1<<PIN)
#define F_CPU 1000000UL  // 1 MHz
#include <util/delay.h>
void LCD_init(void);
void LCD_cmd(unsigned int);
void LCD_data(unsigned char);
int main(void)
{
	int i = 0;
	DDRB = 0xFF;
	LCDport = 0;
	unsigned char str[] = "Hello CDAC! ";
	PIN_SET(DDRC,RS);
	PIN_SET(DDRC,RW);
	PIN_SET(DDRC,EN);
	PIN_CLEAR(PORTC,RS);
	PIN_CLEAR(PORTC,RW);
	PIN_CLEAR(PORTC,EN);
	
	LCD_init();

	while(1)
	{
		for(i = 0 ; str[i] != '\0' ; i++)
		{
				  LCD_data(str[i]);
				 _delay_us 	(40);
		}
		LCD_init();
	}
}
void LCD_init()
{
	 _delay_ms 	( 	200 );  	
	LCD_cmd(0x01);
	 _delay_us 	(40);  	
	LCD_cmd(0x33);
		 _delay_us 	(40);
	LCD_cmd(0x0F);
		 _delay_us 	(40);
	LCD_cmd(0x06);
		 _delay_us 	(40);
}
void LCD_cmd(unsigned int cmd)
{
	PIN_CLEAR(PORTC,RS);
	LCDport = cmd;
	PIN_CLEAR(PORTC,RW);
	PIN_SET(PORTC,EN);
	_delay_us(20);
	PIN_CLEAR(PORTC,EN);
 }
void LCD_data(unsigned char d)
{
	PIN_SET(PORTC,RS);
	LCDport = d;
		PIN_CLEAR(PORTC,RW);
	PIN_SET(PORTC,EN);
	_delay_us(20);
	PIN_CLEAR(PORTC,EN);
 }
		





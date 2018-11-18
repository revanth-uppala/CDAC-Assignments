// ***********************************************************

// Project:

// Author:

// Module description:

// ***********************************************************



#include <avr/io.h>              // Most basic include files

#include <avr/interrupt.h>       // Add the necessary ones

//#include <avr/signal.h>
#define PIN_SET(PORT,PIN) PORT |= (1<<PIN)
#define PIN_CLEAR(PORT,PIN) PORT &= ~(1<<PIN)
#define EN PB4
#define RS PB5
#define RW PB3


#define F_CPU 8000000

  #include<util/delay.h>



         // here



// Define here the global static variables

//
void lcd_init(void)    ;

void lcdcommand(unsigned char cmnd);
void lcddata(unsigned char data);

// It is recommended to use this coding style to

// follow better the mixed C-assembly code in the

// Program Memory window

//

void lcdcommand(unsigned char cmnd)

{
     	unsigned char a,b;

		a= cmnd & 0xf0;

		PORTD = a;
		PIN_CLEAR(PORTB,RS);//RS =  0 for command
		PIN_SET(PORTB,EN);
				_delay_ms(10);

		PIN_CLEAR(PORTB,EN);

		_delay_us(100);

		b= cmnd <<4;
      PORTD = b;
			PIN_CLEAR(PORTB,RS);//RS =  0 for command
		PIN_SET(PORTB,EN);
				_delay_ms(10);

		PIN_CLEAR(PORTB,EN);

	





}



void lcddata(unsigned char data)

{

		unsigned char a,b;
		a=data & 0xf0;
		PORTD = a;
		PIN_SET(PORTB,RS);//RS =1 for data
		PIN_SET(PORTB,EN);
				_delay_ms(10);
		PIN_CLEAR(PORTB,EN);

		_delay_us(100);

		b= data<<4;
      PORTD = b;
		PIN_SET(PORTB,RS);//RS = 1
		PIN_SET(PORTB,EN);
				_delay_ms(10);
		PIN_CLEAR(PORTB,EN);
}



void lcd_init()

{

 lcdcommand(0x28);

  lcdcommand(0x02);

   lcdcommand(0x0e);

    lcdcommand(0x06);

    lcdcommand(0x01);

     lcdcommand(0x80);

}





// ***********************************************************

// Main program

//

int main(void) {





		DDRD = 0xF0; //data port as output

		PIN_SET(DDRB,EN);    //enable as output
		PIN_SET(DDRB,RS);    //RS as output
		PIN_SET(DDRB,RW);    //RW as output

		lcd_init();

		char str[]="HELLO WORLD!";

		char str2[]="WELCOME"   ;

		int i=0;

		



   while(1) {             // Infinite loop; define here the

              while(str[i] != '\0')

              {



                lcddata(str[i++]);

                _delay_ms(10);





				  }

				

				lcdcommand(0xc0);

				i=0;

				

				while(str2[i] != '\0')

              {



                lcddata(str2[i++]);

                _delay_ms(10);



				  }

				  break;

				

				

				 // system behaviour

   }

   		return 0;



}







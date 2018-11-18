// ***********************************************************

// Project:

// Author:

// Module description:

// ***********************************************************



#include <avr/io.h>              // Most basic include files

#include <avr/interrupt.h>       // Add the necessary ones

//#include <avr/signal.h>





#define F_CPU 1000000

  #include<util/delay.h>



         // here



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

void lcdcommand(unsigned char cmnd)

{

		unsigned char a,b;

		a=cmnd & 0xf0;

		PORTB=a|0x04;

		_delay_ms(10);

		PORTB &= ~0x04;

		

		b=cmnd<<4;

		

			PORTB =b| 0x04;

		_delay_ms(10);

		PORTB &= ~0x04;

		

	





}



void lcddata(unsigned char data)

{

		unsigned char a,b;

		a=data & 0xf0;

		PORTB = a|0x05;

		_delay_ms(10);

		PORTB &= ~0x04;

		

		b=data<<4;

		PORTB = b|0x05;

		_delay_ms(10);	

		PORTB &= ~0x04;

		

		

		





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





		DDRC=0xFF;

		DDRB=0xFF;

		lcd_init();

		char str[]="HELLO WORLD!";

		char str2[]="WELCOME";

		int i=0;

		



   while(1) {             // Infinite loop; define here the

              while(str[i] != '\0')

              {



                lcddata(str[i++]);

                _delay_ms(40);





				  }

				

				lcdcommand(0xc0);

				i=0;

				

				while(str2[i] != '\0')

              {



                lcddata(str2[i++]);

                _delay_ms(40);



				  }

				  break;

				

				

				 // system behaviour

   }

   		return 0;



}



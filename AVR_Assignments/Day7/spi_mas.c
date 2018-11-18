// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>
#define F_CPU 1000000UL  // 1 MHz
    //#define F_CPU 14.7456E6
#include <util/delay.h>         // here
#define DDR_SPI DDRB
#define DD_MOSI PB5
#define DD_SCK PB3
#define dataport PORTD
#define SS PB2
// Define here the global static variables
//


// Interrupt handler example for INT0
//

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<SS);
/* Enable SPI, Master*/
SPCR = (1<<SPE)|(1<<MSTR);
}
void SPI_MasterTransmit(char cData)
{
/* Start transmission */
PORTB &=~(1<<SS);
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}
// ***********************************************************
// Main program
//
int main(void) {
	DDRD = 0xFF ; //portD as output
	dataport = 0;
   int data = 0x55;
   PORTB |= (1<<SS);
	SPI_MasterInit();
	while(1) {             // Infinite loop; define here the
      SPI_MasterTransmit(data);
   	dataport = SPDR;
	   _delay_ms(200);
	}

}



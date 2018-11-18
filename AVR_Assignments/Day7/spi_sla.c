// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here
#define DDR_SPI DDRB
#define DD_MISO PB4
#define SS PB2
#define dataport PORTD
// Define here the global static variables
//


// Interrupt handler example for INT0
//


// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDR_SPI = (1<<DD_MISO);
/* Enable SPI */
SPCR = (1<<SPE);
}
char SPI_SlaveReceive(void)
{
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}

// ***********************************************************
// Main program
//
int main(void) {
DDRD = 0xFF;
dataport = 0;
   while(1) {             // Infinite loop; define here the
     // SPDR = 0xAA;
      dataport =   SPI_SlaveReceive();   // system behaviour
   }

}



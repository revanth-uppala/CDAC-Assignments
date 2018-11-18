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
unsigned char eeprom_read(int address)
{
	while(EECR & (1<<EEWE));
	EEAR = address;
	EECR |= (1<<EERE);
	return EEDR;
}
void eeprom_write(int address,char data)
{
	while(EECR &(1<<EEWE));	//Wait until EEWE becomes zero.
	while(SPMCR & (1<<SPMEN));		//Wait until SPMEN in SPMCR becomes zero.
	EEAR = address;									// Write new EEPROM address to EEAR (optional).
	EEDR = data;		//				 Write new EEPROM data to EEDR (optional).
	EECR = 	0x04; 		// Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR.
	EECR |= (1<<EEWE);// Within four clock cycles after setting EEMWE, write a logical one to EEWE.
}
// ***********************************************************
// Main program
//
int main(void) {

  eeprom_write(0x01,2);
  eeprom_write(0x02,4);
  eeprom_write(0x03,6);
	int x = eeprom_read(0x03);
	DDRB = 0xFF;
	PORTB = x;
}




/*
 * jmenotohlejeono.c
 *
 * Created: 04.12.2023 13:14:47
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// Nastavi na vystup
	DDRA=0b00000001;
	DDRC=0b00000100;
	while (1)
	{
		// Rozsviti LED
		PORTA=0b00000001;
		// Pockej 1s
		_delay_ms(1000); 
	    // Vypne LED
		PORTA=0b00000000;
		// Pockej 1s
		_delay_ms(1000);
	}
}
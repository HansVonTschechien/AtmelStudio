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
	DDRA=0b11111111; // Nastavi PA0 na vystup
	while (1)
	{
		// Rozsviti LED
		PORTA=0b11111111;
		_delay_ms(10000); // wait
	 // Vypne LED
		PORTA=0b00000000;
		_delay_ms(10000);
	}
}
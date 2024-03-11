/*
 * GccApplication2.c
 *
 * Created: 29.01.2024 14:19:41
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0b11111111;
	DDRC=0b11111111;
	PORTD=0b10000000;
	
	while (1)
	{
		PORTA=0b00000001;
		PORTC=0b01111110;
		
		PORTA=0b00000010;
		PORTC=0b10111101;
		
		PORTA=0b00000100;
		PORTC=0b11011011;
		
		PORTA=0b00001000;
		PORTC=0b11100111;
		
		PORTA=0b00010000;
		PORTC=0b11100111;
		
		PORTA=0b00100000;
		PORTC=0b11011011;
		
		PORTA=0b01000000;
		PORTC=0b10111101;
		
		PORTA=0b10000000;
		PORTC=0b01111110;
	}
}
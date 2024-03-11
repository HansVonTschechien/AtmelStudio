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
		PORTA=0b10000001;
		PORTC=0b01111110;
		
		_delay_ms(250);
		
		PORTA=0b01000010;
		PORTC=0b10111101;
		
		_delay_ms(250);
		
		PORTA=0b00100100;
		PORTC=0b11011011;
		
		_delay_ms(250);
		
		PORTA=0b00011000;
		PORTC=0b11100111;
		
		_delay_ms(250);
		PORTA=0b00100100;
		PORTC=0b11011011;
		
		_delay_ms(250);
		
		PORTA=0b01000010;
		PORTC=0b10111101;
		
		_delay_ms(250);
		
		PORTA=0b10000001;
		PORTC=0b01111110;
	}
}
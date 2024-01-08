/*
 * jmenotohlejeono.c
 *
 * Created: 04.12.2023 13:14:47
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define c0 0b01111110;
#define c1 0b01001000;
#define c2 0b00111101;
#define c3 0b01101101;
#define c4 0b01001011;
#define c5 0b01100111;
#define c6 0b01110111;
#define c7 0b01001100;
#define c8 0b01111111;
#define c9 0b01101111;

int main(void)
{
	DDRA=0b01111111;
	DDRC=0b00001100;
	while (1)
	{
		uint8_t i;
		for (i = 0; i <= 9; i++)
		{
			cislo(i);
			_delay_ms(1000);
		}
	}
}

void cislo(uint8_t znak) {
	switch(znak) {
		case 0:
			PORTA=c0;
			break;
		case 1:
			PORTA=c1;
			break;
		case 2:
			PORTA=c2;
			break;
		case 3:
			PORTA=c3;
			break;
		case 4:
			PORTA=c4;
			break;
		case 5:
			PORTA=c5;
			break;
		case 6:
			PORTA=c6;
			break;
		case 7:
			PORTA=c7;
			break;
		case 8:
			PORTA=c8;
			break;
		case 9:
			PORTA=c9;
			break;
	}
}
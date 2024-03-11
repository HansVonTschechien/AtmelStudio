/*
 * GccApplication3.c
 *
 * Created: 11.03.2024 14:03:47
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t tis = 0;
uint8_t des = 0;
uint8_t sec = 0;

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
	DDRB=0xFF;
	DDRC|=(1<<PORTC2)|(1<<PORTC3);
	TCCR2|=(1<<WGM21)|(1<<CS21); // prej: zapne rezim CTC na Timer2 a nastavi PS=/8
	OCR2=125-1; // nastaveni vlastniho maxima v CTC rezimu na Timer2
	TIMSK|=(1<<OCIE2); // zapne moznost HW preruseni v CTC na Timer2
	sei(); // globalne vypine funkci HW preruseni
		
	while (1)
	{
		DDRB=0b01111111;
		DDRC=0b00000100;
		
		while (1)
		{
			for (int i = 0; i <= 10; i++)
			{
				DDRC=0b00001000;
				cislo(sec/10);
				_delay_ms(10);
				DDRC=0b00000100;
				cislo(sec%10);
				_delay_ms(10);
			}
		}
	}
}

ISR(TIMER2_COMP_vect) { //ISR je funkce, ktera se zavola pri HW interrupt
	tis++;
	if(tis==100) {
		des++;
		tis=0;
	}
	if(des==10) {
		sec++;
		des=0;
	}
	if(sec==60) {
		sec=0;
	}
}

void cislo(uint8_t znak) {
	switch(znak) {
		case 0:
		PORTB=c0;
		break;
		case 1:
		PORTB=c1;
		break;
		case 2:
		PORTB=c2;
		break;
		case 3:
		PORTB=c3;
		break;
		case 4:
		PORTB=c4;
		break;
		case 5:
		PORTB=c5;
		break;
		case 6:
		PORTB=c6;
		break;
		case 7:
		PORTB=c7;
		break;
		case 8:
		PORTB=c8;
		break;
		case 9:
		PORTB=c9;
		break;
	}
}
/*
 * jmenotohlejeono.c
 *
 * Created: 04.12.2023 13:14:50
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRA = 0b00000001; // Nastavi PA0 na vystup
    while (1) 
    {
		PORTA = 0b00000001; // Rozsviti LED
		_delay_ms(1000);
		PORTA = 0b00000000; // Vypne LED
		_delay_ms(1000);
    }
}


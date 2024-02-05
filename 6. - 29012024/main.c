/*
 * GccApplication2.c
 *
 * Created: 29.01.2024 14:19:41
 * Author : stepan.krousky
 */ 

#define F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xFF;
	DDRC=0b00001100;
	//DDRD=0b00000000;
	PORTD=0b10000000;
	
    while (1) 
    {
        // blika to cervene ale to je jedno zeny jsou taky cerveny
		if (bit_is_clear(PIND, PIND7)) {
			_delay_ms(50);
			if (bit_is_clear(PIND, PIND7)) {
				PORTA=0x77;
			}
		} else {
			PORTA=0;
		};
    };
}


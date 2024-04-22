/*
 * GccApplication3.c
 *
 * Created: 11.03.2024 14:03:47
 * Author : stepan.krousky
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

char data[1];

void sendByte(char znak) {
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = znak;
}

char receiveByte() {
	loop_until_bit_is_set(UCSRA, RXC);
	return UDR;
}

int main(void)
{
	UBRRH = (12>>8);
	UBRRL = 12;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	while (1)
	{
		data[0] = receiveByte();
		sendByte(*data);
		}
}
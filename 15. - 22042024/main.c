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

char arr[] = "Ahoj! \nNebud trouba a zadej sem textik a on se ti vypise mozna v druhem okne!";

void sendByte(char znak) {
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = znak;
}

char receiveByte() {
	loop_until_bit_is_set(UCSRA, RXC);
	return UDR;
}

void displayMenu() {
	for (int i = 0; i < sizeof(arr) / sizeof(char); i++)
	{
		sendByte(arr[i]);
	}
}

int main(void)
{
	UBRRH = (12>>8);
	UBRRL = 12;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	
	displayMenu();
}
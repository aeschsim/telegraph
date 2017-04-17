#include <stdio.h>
#include <string.h>
#include "wiringPi.h"

#include "printer.h"

#define RELAIS_1	4
#define RELAIS_2	5


//Zum testen mit printf, später durch /*Code*/ ersetzen!
void write_short(void)
{	
	digitalWrite(RELAIS_1, HIGH);
	digitalWrite(RELAIS_2, HIGH);
	delay(500*1);
	digitalWrite(RELAIS_2, LOW);
	digitalWrite(RELAIS_1, LOW);
}



void write_long(void)
{
	digitalWrite(RELAIS_1, HIGH);
	digitalWrite(RELAIS_2, HIGH);
	delay(500*4);
	digitalWrite(RELAIS_2, LOW);
	digitalWrite(RELAIS_1, LOW);
}



void write_end(void)
{
	digitalWrite(RELAIS_1, HIGH);
	digitalWrite(RELAIS_2, HIGH);
	delay(500*8);
	digitalWrite(RELAIS_2, LOW);
	digitalWrite(RELAIS_1, LOW);
}



void move(void) 
{
	digitalWrite(RELAIS_2, HIGH);
	delay(500*3);
	digitalWrite(RELAIS_2, LOW);
}

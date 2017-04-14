#include "telegraph.h"
#include <wiringPi.h>

#define RELAIS_1	15
#define RELAIS_2	16

void pencil_down(void)
{
	digitalWrite(RELAIS_1, HIGH);
}



void do_step(int steps)
{
	digitalWrite(RELAIS_2, HIGH);
	delay(2500);
	digitalWrite(RELAIS_2, LOW);	
}



void pencil_up(void) 
{
	digitalWrite(RELAIS_2, LOW);
}




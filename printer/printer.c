#include <stdio.h>
#include <string.h>

#include "printer.h"
#include "telegraph.h"


//Zum testen mit printf, später durch /*Code*/ ersetzen!
void write_short(void)
{
	//printf(".");
	pencil_down();
	do_step(1);
	pencil_up();
}



void write_long(void)
{
	//printf("-");

	pencil_down();
	do_step(4);
	pencil_up();
}



void write_end(void)
{
	//printf("XXX");
	pencil_down();
	do_step(8);
	pencil_up();
}



void move(void) 
{
	printf(" ");
	do_step(3);
}

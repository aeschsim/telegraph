#include <stdio.h>
#include <string.h>

#include "printer.h"

#include <wiringPi.h>
#define RELAIS_1	15
#define RELAIS_2	16

int main(void) {
	wiringPiSetup();
	pinMode(RELAIS_1, OUTPUT);
	pinMode(RELAIS_2, OUTPUT);
	digitalWrite(RELAIS_1, LOW);
	digitalWrite(RELAIS_2, LOW);
	
	printf("Setup done...")
		
	FILE * pFile;
  	char c;
  	
  	pFile=fopen ("morsecode.txt","r");
  	
  	if (pFile==NULL) {
		perror ("Error opening file");
		return 1;
	}
  	
  	while(c != EOF) {
  		c = fgetc(pFile);
  		
  		switch(c) {
  			case '.':
  				write_short();
  				break;
  			case '-':
  				write_long();
  				break;
  			case ' ':
  				move();
  				break;
		  }
		
		move();
	  }
	
	write_end();
    fclose (pFile);
    return 0;
	}

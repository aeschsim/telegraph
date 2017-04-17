#include <stdio.h>
#include <string.h>

#include "printer.h"

#include <wiringPi.h>
#define RELAIS_1	4
#define RELAIS_2	5

int main(void) {
	wiringPiSetup();
	pinMode(RELAIS_1, OUTPUT);
	pinMode(RELAIS_2, OUTPUT);
	digitalWrite(RELAIS_1, LOW);
	digitalWrite(RELAIS_2, LOW);
	delay(2000);
	digitalWrite(RELAIS_1, HIGH);
	digitalWrite(RELAIS_2, HIGH);
	delay(2000);
	digitalWrite(RELAIS_1, LOW);
	digitalWrite(RELAIS_2, LOW);	
	
	printf("Setup done...");
		
	FILE * pFile;
  	char c;
  	
  	pFile = fopen ("morsecode.txt","r");
  	
  	if (pFile==NULL) {
		perror ("Error opening file");
		return 1;
	}
	
	do
   {
      c = fgetc(pFile);
      if( feof(pFile) )
      {
         break ;
      }
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
	delay(100);
	move();
	
   }while(1);

	
  	/*
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
	*/
	write_end();
    fclose (pFile);
    return 0;
	}

#include "printer.h"

#define RELAIS_1	15
#define RELAIS_2	16
#define START		14
 
void setup() 
{
	pinMode(RELAIS_1, OUTPUT);
	pinMode(RELAIS_2, OUTPUT);
	pinMode(START, INPUT);
}

void loop() 
{
	if (digitalRead(START) == HIGH) 
	{
		digitalWrite(RELAIS_1, LOW);
		digitalWrite(RELAIS_2, LOW);
		delay(1000);
		digitalWrite(RELAIS_1, HIGH);
		digitalWrite(RELAIS_2, HIGH);
		delay(1000);
		digitalWrite(RELAIS_1, LOW);
		digitalWrite(RELAIS_2, LOW);	
			
		FILE * pFile;
	  	char c;
	  	
	  	pFile = fopen ("morsecode.txt","r");
	  	
	  	if (pFile==NULL) {
			perror ("Error opening file");
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
	
		move();
		
	   }while(1);
	
		write_end();
	    fclose (pFile);
	}
}

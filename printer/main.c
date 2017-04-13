#include <stdio.h>
#include <string.h>

#include "printer.h"

int main(void) {

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

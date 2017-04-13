#include <stdio.h>
#include <string.h>

#include "ascii_to_morse.h"
#include "ascii_to_morsefile.h"

#define STRLEN 100

/*
Some parts of this Code are copyed from https://www.programmieraufgaben.ch
*/


int main(void)
{
    char text[STRLEN];

    printf("Geben sie den Text ein (um zu Beenden druecken sie Enter):\n");
    fgets(text, sizeof(text), stdin);          // reading in the text
    text[strlen(text)-1] = '\0';                  // cutting off the \n

    printf("\n");

    translate_to_morse(text);               // main translation function
	
	FILE * pFile;

   	pFile = fopen ("morsecode.txt","w");

	translate_to_morsefile(text, pFile);

   	fclose (pFile);
	
	return 0;
}

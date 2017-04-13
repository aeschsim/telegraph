#include <stdio.h>
#include <string.h>

#include "ascii_to_morse.h"

// converts ascii-characters into morse code

void ascii_to_morse(char character)
{
    switch(character)
    {

        // letters

        case 'a':
        case 'A':
            printf(".- ");
            break;

        case 'b':
        case 'B':
            printf("-... ");
            break;

        case 'c':
        case 'C':
            printf("-.-. ");
            break;

        case 'd':
        case 'D':
            printf("-.. ");
            break;

        case 'e':
        case 'E':
            printf(". ");
            break;

        case 'f':
        case 'F':
            printf("..-. ");
            break;

        case 'g':
        case 'G':
            printf("--. ");
            break;

        case 'h':
        case 'H':
            printf(".... ");
            break;

        case 'i':
        case 'I':
            printf(".. ");
            break;

        case 'j':
        case 'J':
            printf(".--- ");
            break;

        case 'k':
        case 'K':
            printf("-.- ");
            break;

        case 'l':
        case 'L':
            printf(".-.. ");
            break;

        case 'm':
        case 'M':
            printf("-- ");
            break;

        case 'n':
        case 'N':
            printf("-. ");
            break;

        case 'o':
        case 'O':
            printf("--- ");
            break;

        case 'p':
        case 'P':
            printf(".--. ");
            break;

        case 'q':
        case 'Q':
            printf("--.- ");
            break;

        case 'r':
        case 'R':
            printf(".-. ");
            break;

        case 's':
        case 'S':
            printf("... ");
            break;

        case 't':
        case 'T':
            printf("- ");
            break;

        case 'u':
        case 'U':
            printf("..- ");
            break;

        case 'v':
        case 'V':
            printf("...- ");
            break;

        case 'w':
        case 'W':
            printf(".-- ");
            break;

        case 'x':
        case 'X':
            printf("-..- ");
            break;

        case 'y':
        case 'Y':
            printf("-.-- ");
            break;

        case 'z':
        case 'Z':
            printf("--.. ");
            break;



        // spaces

        case ' ':
            printf("  ");
            break;



        // numbers

        case '0':
            printf("----- ");
            break;

        case '1':
            printf(".---- ");
            break;

        case '2':
            printf("..--- ");
            break;

        case '3':
            printf("...-- ");
            break;

        case '4':
            printf("....- ");
            break;

        case '5':
            printf("..... ");
            break;

        case '6':
            printf("....- ");
            break;

        case '7':
            printf("...-- ");
            break;

        case '8':
            printf("..--- ");
            break;

        case '9':
            printf(".---- ");
            break;



        // punctuation marks

        case '.':
            printf(".-.-.- ");
            break;

        case ',':
            printf("--..-- ");
            break;

        case ':':
            printf("---... ");
            break;

        case ';':
            printf("-.-.-. ");
            break;

        case '?':
            printf("..--.. ");
            break;

        case '-':
            printf("-....- ");
            break;

        case '_':
            printf("..--.- ");
            break;

        case '(':
            printf("-.--. ");
            break;

        case ')':
            printf("-.--.- ");
            break;

        case '\'':
            printf(".----. ");
            break;

        case '=':
            printf("-...- ");
            break;

        case '+':
            printf(".-.-. ");
            break;

        case '/':
            printf("-..-. ");
            break;

        case '@':
            printf(".--.-. ");
            break;



        // special characters

        case 1:
            printf(".-.- ");
            break;

        case 2:
            printf("---. ");
            break;

        case 3:
            printf("..--- ");
            break;

        case 4:
            printf("---- ");
            break;

        case 5:
            printf("...--.. ");
            break;



        default:
            printf("........ ");

    }
}


// checks if there is a Ä, Ö, Ü, CH or ß

int check_special_character(char string[], int position)
{
    if(string[position] == 'A' || string[position] == 'a')
        if(string[position+1] == 'E' || string[position+1] == 'e')
            return 1;

    if(string[position] == 'O' || string[position] == 'o')
        if(string[position+1] == 'E' || string[position+1] == 'e')
            return 2;

    if(string[position] == 'U' || string[position] == 'u')
        if(string[position+1] == 'E' || string[position+1] == 'e')
            return 3;

    if(string[position] == 'C' || string[position] == 'c')
        if(string[position+1] == 'H' || string[position+1] == 'h')
            return 4;

    if(string[position] == 'S' || string[position] == 's')
        if(string[position+1] == 'S' || string[position+1] == 's')
            return 5;

    return 0;
}


// main translation function

void translate_to_morse(char text[])
{
    int length = strlen(text);
    int special;
    int i;
    char character;

    for(i = 0; i < length; i++)     // translation loop
    {
        character = 0;

        if(!(i+1 == length))
            special = check_special_character(text, i);     // checks special characters
        else
            special = 0;

        if(special != 0)                                    // handles special characters
        {
            character = special;
            length--;
            i++;
        }

        if(character == 0)                                  // handles non-special characters
            character = text[i];

        ascii_to_morse(character);                          // converts characters to morse code

    }
}

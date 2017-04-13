#include <stdio.h>
#include <string.h>

#include "ascii_to_morsefile.h"

void ascii_to_morsefile(char character, FILE *pFile)
{
	 switch(character)
    {
        // letters

        case 'a':
        case 'A':
            fprintf(pFile, ".- ");
            break;

        case 'b':
        case 'B':
            fprintf(pFile, "-... ");
            break;

        case 'c':
        case 'C':
            fprintf(pFile, "-.-. ");
            break;

        case 'd':
        case 'D':
            fprintf(pFile, "-.. ");
            break;

        case 'e':
        case 'E':
            fprintf(pFile, ". ");
            break;

        case 'f':
        case 'F':
            fprintf(pFile, "..-. ");
            break;

        case 'g':
        case 'G':
            fprintf(pFile, "--. ");
            break;

        case 'h':
        case 'H':
            fprintf(pFile, ".... ");
            break;

        case 'i':
        case 'I':
            fprintf(pFile, ".. ");
            break;

        case 'j':
        case 'J':
            fprintf(pFile, ".--- ");
            break;

        case 'k':
        case 'K':
            fprintf(pFile, "-.- ");
            break;

        case 'l':
        case 'L':
            fprintf(pFile, ".-.. ");
            break;

        case 'm':
        case 'M':
            fprintf(pFile, "-- ");
            break;

        case 'n':
        case 'N':
            fprintf(pFile, "-. ");
            break;

        case 'o':
        case 'O':
            fprintf(pFile, "--- ");
            break;

        case 'p':
        case 'P':
            fprintf(pFile, ".--. ");
            break;

        case 'q':
        case 'Q':
            fprintf(pFile, "--.- ");
            break;

        case 'r':
        case 'R':
            fprintf(pFile, ".-. ");
            break;

        case 's':
        case 'S':
            fprintf(pFile, "... ");
            break;

        case 't':
        case 'T':
            fprintf(pFile, "- ");
            break;

        case 'u':
        case 'U':
            fprintf(pFile, "..- ");
            break;

        case 'v':
        case 'V':
            fprintf(pFile, "...- ");
            break;

        case 'w':
        case 'W':
            fprintf(pFile, ".-- ");
            break;

        case 'x':
        case 'X':
            fprintf(pFile, "-..- ");
            break;

        case 'y':
        case 'Y':
            fprintf(pFile, "-.-- ");
            break;

        case 'z':
        case 'Z':
            fprintf(pFile, "--.. ");
            break;



        // spaces

        case ' ':
            fprintf(pFile, "  ");
            break;



        // numbers

        case '0':
            fprintf(pFile, "----- ");
            break;

        case '1':
            fprintf(pFile, ".---- ");
            break;

        case '2':
            fprintf(pFile, "..--- ");
            break;

        case '3':
            fprintf(pFile, "...-- ");
            break;

        case '4':
            fprintf(pFile, "....- ");
            break;

        case '5':
            fprintf(pFile, "..... ");
            break;

        case '6':
            fprintf(pFile, "....- ");
            break;

        case '7':
            fprintf(pFile, "...-- ");
            break;

        case '8':
            fprintf(pFile, "..--- ");
            break;

        case '9':
            fprintf(pFile, ".---- ");
            break;



        // punctuation marks

        case '.':
            fprintf(pFile, ".-.-.- ");
            break;

        case ',':
            fprintf(pFile, "--..-- ");
            break;

        case ':':
            fprintf(pFile, "---... ");
            break;

        case ';':
            fprintf(pFile, "-.-.-. ");
            break;

        case '?':
            fprintf(pFile, "..--.. ");
            break;

        case '-':
            fprintf(pFile, "-....- ");
            break;

        case '_':
            fprintf(pFile, "..--.- ");
            break;

        case '(':
            fprintf(pFile, "-.--. ");
            break;

        case ')':
            fprintf(pFile, "-.--.- ");
            break;

        case '\'':
            fprintf(pFile, ".----. ");
            break;

        case '=':
            fprintf(pFile, "-...- ");
            break;

        case '+':
            fprintf(pFile, ".-.-. ");
            break;

        case '/':
            fprintf(pFile, "-..-. ");
            break;

        case '@':
            fprintf(pFile, ".--.-. ");
            break;



        // special characters

        case 1:
            fprintf(pFile, ".-.- ");
            break;

        case 2:
            fprintf(pFile, "---. ");
            break;

        case 3:
            fprintf(pFile, "..--- ");
            break;

        case 4:
            fprintf(pFile, "---- ");
            break;

        case 5:
            fprintf(pFile, "...--.. ");
            break;



        default:
            fprintf(pFile, "........ ");

    }
}

void translate_to_morsefile(char text[], FILE *pFile)
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

        ascii_to_morsefile(character, pFile);                          // converts characters to morse code

    }
}

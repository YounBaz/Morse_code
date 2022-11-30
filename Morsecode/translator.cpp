#include "translator.h"
#include <string.h>
#include <Arduino.h>
Translator::Translator(int pin)
{
    mor = morsecode(pin);
}

Translator::~Translator()
{
  strcpy(trad, "");
}

Translator::Translator()
{
    mor = morsecode();
}

void Translator::Translate(char c) // This function replace every letter or number with its morse code
{   
    switch (c)
    {
    case 'a':
    case 'A':
        strcat(trad,".-");
        strcat(trad," "); 
        break;
    default:
        break;
    case 'b':
    case 'B':
        strcat(trad,"-...");
        strcat(trad," ");
        break;
    case 'c':
    case 'C':
        strcat(trad,"-.-.");
        strcat(trad," ");
        break;
    case 'd':
    case 'D':
        strcat(trad,"-..");
        strcat(trad," ");
        break;
    case 'e':
    case 'E':
        strcat(trad,".");
        strcat(trad," ");
        break;
    case 'f':
    case 'F':
        strcat(trad,"..-.");
        strcat(trad," ");
        break;
    case 'g':
    case 'G':
        strcat(trad,"--.");
        strcat(trad," ");
        break;
    case 'h':
    case 'H':
        strcat(trad,"....");
        strcat(trad," ");
        break;
    case 'i':
    case 'I':
        strcat(trad,"..");
        strcat(trad," ");
        break;
    case 'j':
    case 'J':
        strcat(trad,".---");
        strcat(trad," ");
        break;
    case 'k':
    case 'K':
        strcat(trad,"-.-");
        strcat(trad," ");
        break;
    case 'l':
    case 'L':
        strcat(trad,".-..");
        strcat(trad," ");
        break;
    case 'm':
    case 'M':
        strcat(trad,"--");
        strcat(trad," ");
        break;
    case 'n':
    case 'N':
        strcat(trad,"-.");
        strcat(trad," ");
        break;
    case 'o':
    case 'O':
        strcat(trad,"---");
        strcat(trad," ");
        break;
    case 'p':
    case 'P':
        strcat(trad,".--.");
        strcat(trad," ");
        break;
    case 'q':
    case 'Q':
        strcat(trad,"--.-");
        strcat(trad," ");
        break;
    case 'r':
    case 'R':
        strcat(trad,".-.");
        strcat(trad," ");
        break;
    case 's':
    case 'S':
        strcat(trad,"...");
        strcat(trad," ");
        break;
    case 't':
    case 'T':
        strcat(trad,"-");
        strcat(trad," ");
        break;
    case 'u':
    case 'U':
        strcat(trad,"..-");
        strcat(trad," ");
        break;
    case 'v':
    case 'V':
        strcat(trad,"...-");
        strcat(trad," ");
        break;
    case 'w':
    case 'W':
        strcat(trad,".--");
        strcat(trad," ");
        break;
    case 'x':
    case 'X':
        strcat(trad,"-..-");
        strcat(trad," ");
        break;
    case 'y':
    case 'Y':
        strcat(trad,"-.--");
        strcat(trad," ");
        break;
    case 'z':
    case 'Z':
        strcat(trad,"--..");
        strcat(trad," ");
        break;
    case '0':
        strcat(trad,"-----");
        strcat(trad," ");
        break;
    case '1':
        strcat(trad,".----");
        strcat(trad," ");
        break;
    case '2':
        strcat(trad,"..---");
        strcat(trad," ");
        break;
    case '3':
        strcat(trad,"...--");
        strcat(trad," ");
        break;
    case '4':
        strcat(trad,"....-");
        strcat(trad," ");
        break;
    case '5':
        strcat(trad,".....");
        strcat(trad," ");
        break;
    case '6':
        strcat(trad,"-....");
        strcat(trad," ");
        break;
    case '7':
        strcat(trad,"--...");
        strcat(trad," ");
        break;
    case '8':
        strcat(trad,"---..");
        strcat(trad," ");
        break;
    case '9':
        strcat(trad,"----.");
        strcat(trad," ");
        break;
    case ' ':              // The space between two words
        strcat(trad,"+");
        break;
    }
}

void Translator::action() // flashing the morsecode with the led inside the Arduino
{
    for (int i = 0; i < strlen(trad); i++)
    {
        if (trad[i] == '.')
        {
            mor.dot();
        }
        else if (trad[i] == '-')
        {
            mor.dash();
        }
        else if (trad[i] == ' ')
        {
            mor.space();
        }
        else if (trad[i] == '+')
        {
            mor.bigspace();
        }
        else
        {
            break;
        }
    }
}

void Translator::Translateword(char word[]) // Translation of the word
{
    for (int i = 0; i < strlen(word); i++)
    {
        Translate(word[i]);
    }
}

void Translator::refreshtrans()
{
  strcpy(trad, "");
}
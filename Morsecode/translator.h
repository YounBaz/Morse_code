#ifndef Translator_h
#define Translator_h

#include "Morsecode.h"
#include <string.h>
class Translator
{
private:
    morsecode mor;
public:
    Translator(int pin);
    Translator();
    ~Translator();
    void Translate(char c);
    void Translateword(char word[]);
    char trad[1024];
    void action();
    void refreshtrans();
};


#endif
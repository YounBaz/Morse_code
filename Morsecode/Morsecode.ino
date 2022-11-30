#include <Arduino.h>
#include "Morsecode.h"
#include "Translator.h"

morsecode m(LED_BUILTIN);
char sentence[50]= "1"; //put your sentence here
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Translator Translator(LED_BUILTIN); 
  Translator.refreshtrans(); 
  Translator.Translateword(sentence);
  Translator.action();
}
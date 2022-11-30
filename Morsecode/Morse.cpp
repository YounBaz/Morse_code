#include "Morsecode.h"
#include <Arduino.h>

morsecode::morsecode(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

morsecode::morsecode()
{
  pinMode(LED_BUILTIN, OUTPUT);
  _pin = LED_BUILTIN;
}

morsecode::~morsecode(){}

void morsecode::dot() //The flashing for a dot
{
  currenttime = millis();
  while(millis() < currenttime + 250){digitalWrite(_pin, HIGH);} 
  currenttime = millis();
  while(millis() < currenttime + 250){digitalWrite(_pin, LOW);} 
}

void morsecode::dash() // The flashing for a dash
{
  currenttime = millis();
  while(millis() < currenttime + 1000){digitalWrite(_pin, HIGH);} 
  currenttime = millis();
  while(millis() < currenttime + 250){digitalWrite(_pin, LOW);} 
}
void morsecode::space() //The space between two letter 
{
  currenttime = millis();
  while(millis() < currenttime + 750){digitalWrite(_pin, LOW);} 
}
void morsecode::bigspace()//The space between two words
{
  currenttime = millis();
  while(millis() < currenttime + 1750){digitalWrite(_pin, LOW);} 
}
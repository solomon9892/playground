#pragma once
#include <main.h>


struct horn
{
  int pin;
  int ON;
  horn(int PIN)
  {
    pinMode(PIN, OUTPUT);
    pin = PIN;
    Serial.println("ALARM ON");
    delay(2000);
  }
  
  void bleep()
  {

   digitalWrite(pin, HIGH);
   delay(20);
   digitalWrite(pin, LOW);
   delay(20);

  }

  void bleepFor(int bleepcount)
  {
    if (ON != 0)
    {
    for(auto x = 0; x < bleepcount; x++)
    {
        bleep();
    }
    }
    
  }

  int isOn(int on)
  {
     return ON = on;
  }

};


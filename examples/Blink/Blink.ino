/*
 * Creada por Israel Barreras
 * Licencia de uso libre
 * https://tecnoingenia.com
 */
 
#include <AutoTimer.h>

#define DELAY_TIME 200

void toggleLED()
{  
  digitalWrite(13, !digitalRead(13)); 
}

AutoTimer blink(toggleLED, DELAY_TIME, true);

void setup() 
{
  pinMode(13, OUTPUT); 
}

void loop() 
{  
  blink.evaluate();
}

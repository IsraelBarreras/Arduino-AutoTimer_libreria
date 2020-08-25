/*
 * Creada por Israel Barreras
 * Licencia de uso libre
 * https://tecnoingenia.com
 */
 
#include <AutoTimer.h>

void toggleLED()
{
  
  if(digitalRead(13))
  {
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
  }
  
}

void conteo(){
  Serial.println(millis());
}

AutoTimer parpadeo(toggleLED, 200, true);
AutoTimer contador(conteo, 1000, false);

void setup() {
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
}

void loop() {
  
  parpadeo.evaluate();
  contador.evaluate();
  
}

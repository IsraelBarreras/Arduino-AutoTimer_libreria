/*
 * Creada por Israel Barreras
 * Licencia de uso libre
 * https://tecnoingenia.com
 */
 
#include <AutoTimer.h>

void toggleLED(){
  
  if(digitalRead(13))
  {
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
  }
  
}
AutoTimer parpadeo(toggleLED, 100, true);

boolean mode = false;
void frequencyDriver(){

  unsigned long newFrequency;
  if(mode){
   newFrequency = parpadeo.getDelayTime() + 5; 
  }
  else{
    newFrequency = parpadeo.getDelayTime() - 5;
  }
      
  parpadeo.setDelayTime(newFrequency);

  if(newFrequency <= 10){
    mode = true;
  }
  else if(newFrequency >= 300){
    mode = false;
  }

}


AutoTimer variador(frequencyDriver, 200, false);

void setup() {
  
  pinMode(13, OUTPUT);
  
}

void loop() {
  
  parpadeo.evaluate();
  variador.evaluate();
  
}

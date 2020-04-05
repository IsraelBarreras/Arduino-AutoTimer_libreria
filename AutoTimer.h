/*
 * Creada por Israel Barreras
 * Licencia de uso libre
 * https://tecnoingenia.com
 */

#ifndef AutoAutoTimer_h
#define AutoTimer_h

#include "Arduino.h"

class AutoTimer
{
  private:
    unsigned long lastUpdate;
    boolean       inicialWait;
    void          (*funcion)(void);
    unsigned long delayTime;
    
  public:
    AutoTimer(void(*f)(void), unsigned long d); //Constructor
    AutoTimer(void(*f)(void), unsigned long d, boolean iW); //Constructor opción 2
    boolean evaluate();
    boolean setDelayTime(unsigned long d);
    unsigned long getDelayTime();
    
};

#endif

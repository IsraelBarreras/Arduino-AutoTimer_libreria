/*
 * by Israel Barreras
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
    AutoTimer(void(*f)(void), unsigned long d);
    AutoTimer(void(*f)(void), unsigned long d, boolean iW); 
    boolean evaluate(void);
    boolean run(void);
    boolean setDelayTime(unsigned long d);
    unsigned long getDelayTime(void);
    
};

#endif

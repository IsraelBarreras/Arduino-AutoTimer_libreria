/*
 * by Israel Barreras
 * Licencia de uso libre
 * https://tecnoingenia.com
 */

#include "Arduino.h"
#include "AutoTimer.h"


/****************************************************************************
* Función: Constructor 1
* Descripción: Contructor de objeto AutoTimer, recibe como parámetros la
* función a ejecutar y el tiempo de delay entre cada ejecución en milisegundos
* este contrucctor ejecuta la función inmediatamente al ejecutar AutoTimer.evaluate() 
*****************************************************************************/
AutoTimer::AutoTimer(void(*f)(void), unsigned long d) 
{
  inicialWait = false;
  funcion = f;
  delayTime = d;  
  this->run();
}


/****************************************************************************
* Función: Constructor 2
* Descripción: Contructor de objeto AutoTimer, recibe como parámetros la
* función a ejecutar, el tiempo de delay entre cada ejecución en milisegundos
* y un dato booleano "iW" TRUE = daley inicial, FALSE = ejecución inmediata
*****************************************************************************/
AutoTimer::AutoTimer(void(*f)(void), unsigned long d, boolean iW) //Constructor opción 2
{

  inicialWait = iW;
  funcion = f;
  delayTime = d;
  lastUpdate = millis();
  if(!inicialWait)
  {
    this->run();
  }
  
}


/****************************************************************************
* Función: evaluate
* Descripción: Este método evalua si es tiempo de ejecutar la función
*****************************************************************************/
boolean AutoTimer::evaluate()
{

  if(lastUpdate > millis()) //Esto es en caso de que ocurra un desbordamiento de la función millis
  {
    lastUpdate = millis();
  }
   
  if(millis() - lastUpdate >= delayTime)
  {
    this->run();
    return true;
  }
  return false;

}


/****************************************************************************
* Función: run
* Descripción: Este método ejecuta inmediatamente la función
*****************************************************************************/
boolean AutoTimer::run()
{

  (*funcion)();
  lastUpdate = millis();
  return true;

}


/****************************************************************************
* Función: setDelayTime
* Descripción: Ajusta un nuevo delay entre ejecuciones en milisegundos
*****************************************************************************/
boolean AutoTimer::setDelayTime(unsigned long d)
{

  delayTime = d;
  return true;

}


/****************************************************************************
* Función: getDelayTime
* Descripción: Regresa el tiempo de delay actual en milisegundos
*****************************************************************************/
unsigned long AutoTimer::getDelayTime()
{

  return delayTime;

}

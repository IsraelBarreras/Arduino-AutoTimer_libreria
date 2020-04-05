# AutoTimer

Auto timer es una librería dedicada a facilitar la programación de procesos que se deben repetir cada determinado tiempo durante el la ejecución del código. Especialmente dirigida para principiantes que quieran pasar del "delay".

## ¿Cómo usar?

- Declaramos nuestro objeto AutoTimer


```cpp
AutoTimer autoTimer(funcion, delayTime, inicialWait);
```


donde:

**inicialWait**: un booleano que indicará si queremos que la función se ejecute inmediatamente la primer vez o queremos que espere.

**funcion**: es un apuntador a la función que queremos ejecutar.

**delayTime**: que es el tiempo en milisegundos que queremos esperar entre cada ejecución.

- En nuestro loop() escibimos:


```cpp
autoTimer.evaluate();
```


Listo nuestra función se repetira cada que se cumpla el tiempo asignado.

para una descripción más a detalle véase en: https://tecnoingenia.com/2019/11/14/arduino-orientado-a-objetos-y-creacion-de-librerias/

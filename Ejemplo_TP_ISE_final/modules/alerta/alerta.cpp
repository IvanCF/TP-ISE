
#include "mbed.h"
#include "alerta.h"

//=====[Declaration and initialization of public global objects]===============

DigitalOut luzLed(D11);


//=====[Implementations of public functions]===================================
void alertaUpdate(int valor)
{
     if ( valor == 1 )  {
            
            luzLed = 1;
        }
     else
     {
         luzLed= 0;
     }   
    
}

//=====[Implementations of private functions]==================================

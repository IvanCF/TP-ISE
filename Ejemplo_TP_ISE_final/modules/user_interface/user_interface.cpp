//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "user_interface.h"
#include "smart_home_system.h"
#include "humedad_sensor.h"
#include "display.h"
#include "alerta.h"
#include "sensor_ds1820.h"

//=====[Declaration of private defines]======================================

#define DISPLAY_REFRESH_TIME_MS 1000


//=====[Declaration and initialization of public global objects]===============
DigitalOut incorrectCodeLed(LED3);
DigitalOut systemBlockedLed(LED2);
unsigned long n;

//=====[Declarations (prototypes) of private functions]========================


static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{

    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    
    userInterfaceDisplayUpdate();
}

//=====[Implementations of private functions]==================================

static void userInterfaceDisplayInit()
{
    displayInit();
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Te:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Hu:" );
    
   
    temperatureSensorInit2();
    
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char temperatureString[6];
    float cantidadHumedad=0.0;
    char humedadString[7];
    
    if( accumulatedDisplayTime >=
        DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;
        
        
        //se lee el sensor humedad
        displayCharPositionWrite (3,1);
        
        cantidadHumedad=humedadSensorRead();
        sprintf(humedadString, "%3.2f %%",cantidadHumedad);
        printf("hum: %2.2f \n",humedadString);
        displayStringWrite( humedadString );
        
        // se lee la temperatura
        sprintf(temperatureString, "%3.2f", temperatureSensorReadCelsius2());
        displayCharPositionWrite ( 3,0 );
        displayStringWrite( temperatureString );
        displayCharPositionWrite ( 8,0 );
        displayStringWrite( "'C " );

        displayCharPositionWrite ( 12,0 );
        displayStringWrite( "H2O" );
        displayCharPositionWrite ( 11,1 );
        if (cantidadHumedad >=0.7) 
        {   alertaUpdate(1);
            displayStringWrite( "AYUDA" );
            printf("\n---- ayuda ----\n ");
            
        } else {
          alertaUpdate(0);
           displayStringWrite( " OK  " );
        }
        

    } else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}

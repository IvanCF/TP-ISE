//=====[Libraries]=============================================================

#include "mbed.h"
#include "humedad_sensor.h"

//=====[Declaration of private defines]======================================
#define NUMBER_OF_AVG_SAMPLES    20


//=====[Declaration and initialization of public global objects]===============

AnalogIn sensorSuelo(A0);
float valorHumedad;


//=====[Implementations of public functions]===================================

void humedadSensorInit()
{
    valorHumedad=0.0;
}

void humedadSensorUpdate()
{
    static int dsSampleIndex = 0;
    float dsReadingsSum = 0.0;
    float dsReadingsAverage = 0.0;
    
    for (int i = 0; i < NUMBER_OF_AVG_SAMPLES; i++) {
        
        float lectura=sensorSuelo.read();
        dsReadingsSum = dsReadingsSum + lectura;
    }
    dsReadingsAverage = dsReadingsSum / NUMBER_OF_AVG_SAMPLES;
         
    valorHumedad=dsReadingsAverage;
}

float humedadSensorRead()
{
    humedadSensorUpdate(); 
    return valorHumedad;
}

//=====[Implementations of private functions]==================================

//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "smart_home_system.h"
#include "user_interface.h"
#include "sensor_ds1820.h"
#include "humedad_sensor.h"


//=====[Implementations of public functions]===================================

void smartHomeSystemInit()
{
    userInterfaceInit();
    humedadSensorInit();
}

void smartHomeSystemUpdate()
{
    humedadSensorUpdate();
    userInterfaceUpdate();
  
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================

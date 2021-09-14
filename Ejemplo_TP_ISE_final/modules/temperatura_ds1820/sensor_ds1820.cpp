#include "mbed.h"
#include "platform/mbed_thread.h"
#include "arm_book_lib.h"
#include "DS1820.h"




#define DATA_PIN        D10
#define MAX_PROBES      16

DS1820* probe[MAX_PROBES];


int     DS;
float   Temp[16]; 
float temperatura=0.0;

void temperatureSensorInit2()
{

 printf("Iniciando sensor Hum...!\n\n");

    while (DS1820::unassignedProbe(DATA_PIN)) {
        probe[DS] = new DS1820(DATA_PIN);
        DS++;
        if (DS == MAX_PROBES) {
            break;
        }
    }
    
    if (!DS) {        
        printf("No Sensors found!\n\n");
        //ThisThread::sleep_for(chrono::milliseconds(1000));
        NVIC_SystemReset();
    }

    // set each probe resolution, default is 12bit (750ms)
    probe[0]->setResolution(9);
//    probe[0]->setResolution(10);
//    probe[0]->setResolution(11);
//    probe[0]->setResolution(12);
//    probe[1]->setResolution(9);
//    probe[2]->setResolution(10);

    //t.start();
}
    
void temperatureSensorUpdate2()
{
   // printf(" Sensor data..\n\n");

        int DS_error = 0;
        for (int i = 0; i < DS; i++) {
            Temp[i] = probe[i]->temperature();
            if(Temp[i]==-1000) {
                Temp[i] = probe[i]->temperature();  // get read temp again if error
                DS_error++;
            }
            printf("Lectura %d:  %3.2f %cc\r\n",i,Temp[i],0xb0);
            
            temperatura=Temp[i];
        }
       // printf("\nDS errors:  %d\n\n", DS_error);

       // printf("Start conversion\n");
       // t.reset();
        // don't wait for conversion, but do something that takes at least 750ms before reading the sensors
        //if(DS>0){probe[0]->convertTemperature(0, DS1820::all_devices);}
        
        // wait for conversion, can take up to 750ms(12 bit mode)
        if(DS>0){probe[0]->convertTemperature(1, DS1820::all_devices);}        
        
       // printf("\nConvert process time: %0.6f Seconds\n", chrono::duration<float>(t.elapsed_time()).count());

       // ThisThread::sleep_for(chrono::milliseconds(1000));
}
float temperatureSensorReadCelsius2()
{
    temperatureSensorUpdate2();
    return temperatura;
}

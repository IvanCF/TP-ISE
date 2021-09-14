//=====[DATOS DEL AUTOR]=======================================================
/*
[+] NOMBRE: Daniel Ivan Cruz Flores
[+] MATERIA: Introducción a Sistemas Embebidos
[+] EMAIL: ivan17cf@gmail.com
[+] Laboratorio de Sistemas Embebidos - UBA

*/

//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}
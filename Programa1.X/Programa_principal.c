/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include "Configuracion.h"

void main(void) {
    TRISD = 0x00; // PUERTO D SALIDA
    TRISB = 0xFF; // PUERTO B ENTRADA
    LATD = 0x00;
    LATDbits.LATD0 = 1; // Enable 
    while(1){
        if(PORTBbits.RB0 == 0){
            LATDbits.LATD1 = 1;
            LATDbits.LATD2 = 0;
        }
        else if(PORTBbits.RB1 == 0){
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
        }
        else{
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
        }
    }
    return;
}

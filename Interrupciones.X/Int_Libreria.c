
#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Int_Libreria.h"

uint8_t x = 0;

void INT_Init (void){
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    INTCONbits.INT0IE = 1; // Habilitar INT0
    INTCONbits.INT0IF = 0; // APagamos la bandera
    INTCON3bits.INT1E = 1; // Habilitar INT1
    INTCON3bits.INT1F = 0;// Apagamos la bandera
    INTCON2bits.INTEDG0 = 0;
    INTCON2bits.INTEDG1 = 0; // Flanco de bajada
    INTCON3bits.INT1IP = 0;
    RCONbits.IPEN = 1; // Habilitando todas prioridades
    INTCONbits.GIEL = 1; // Habilitando prioridades bajadas
    INTCONbits.GIEH = 1; // Habilitamos prioridades altas
}

void __interrupt(high_priority) INT0_ISR(void){
    if(INTCONbits.INT0IF){
        x = 1;
        INTCONbits.INT0IF = 0;
    }
}

void __interrupt(low_priority) INT1_ISR(void){
    if(INTCON3bits.INT1F){
        x = 2;
        INTCON3bits.INT1F = 0;
    }
}

//void INT_Init (void){
//    TRISBbits.RB0 = 1;
//    INTCONbits.INT0IE = 1; // Habilitar INT0
//    INTCONbits.INT0IF = 0; // APagamos la bandera
//    INTCON2bits.INTEDG0 = 0;
//    INTCONbits.PEIE = 1; // Habilitando perifericos
//    INTCONbits.GIE = 1; //Globales
//}
//
//void __interrupt() INT0_ISR(void){
//    LATDbits.LATD0 = ~LATDbits.LATD0;
//    INTCONbits.INT0IF = 0;
//}

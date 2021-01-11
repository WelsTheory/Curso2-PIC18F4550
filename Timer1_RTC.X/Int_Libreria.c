
#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Int_Libreria.h"

int sec = 8, sec_d = 5, min = 9, min_d = 5, hor = 9, hor_d = 1;

void INT_Init (void){
//    TRISBbits.RB0 = 1;
//    TRISBbits.RB1 = 1;
//    INTCONbits.INT0IE = 1; // Habilitar INT0
//    INTCONbits.INT0IF = 0; // APagamos la bandera
//    INTCON3bits.INT1E = 1; // Habilitar INT1
//    INTCON3bits.INT1F = 0;// Apagamos la bandera
//    INTCON2bits.INTEDG0 = 0;
//    INTCON2bits.INTEDG1 = 0; // Flanco de bajada
//    INTCON3bits.INT1IP = 0;
    RCONbits.IPEN = 1; // Habilitando todas prioridades
    INTCONbits.GIEL = 1; // Habilitando prioridades bajadas
    INTCONbits.GIEH = 1; // Habilitamos prioridades altas
}

void __interrupt(high_priority) INT0_ISR(void){
    
}

void __interrupt(low_priority) TMR1_ISR(void){
    sec++;
    if(sec == 10){
        sec = 0;
        sec_d++;
    }
    if(sec_d == 6){
        sec_d = 0;
        min++;
    }
    if(min == 10){
        min = 0;
        min_d++;
    }
    if(min_d == 6){
        min_d = 0;
        hor++;
    }
    if(hor == 10){
        hor = 0;
        hor_d++;
    }
    
    if(hor == 4 && hor_d == 2){
        hor = 0;
        hor_d = 0;
    }
//    if(TMR0L == 0x00){
        TMR1H = 0x80;
        TMR1L = 0x00;
//    }
    //x++;
    //if(x >= 100){
        LATDbits.LATD0 = ~LATDbits.LATD0;
    //}
    PIR1bits.TMR1IF = 0;
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

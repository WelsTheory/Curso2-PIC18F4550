
#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Int_Libreria.h"
#include "Timer0_8bit.h"

extern uint8_t x;
uint8_t y = 0;
uint8_t a = 0;
uint16_t b = 0;

void INT_Init (void){
    TRISBbits.RB0 = 1;
    //TRISBbits.RB1 = 1;
    INTCONbits.INT0IE = 1; // Habilitar INT0
    INTCONbits.INT0IF = 0; // APagamos la bandera
//    INTCON3bits.INT1E = 1; // Habilitar INT1
//    INTCON3bits.INT1F = 0;// Apagamos la bandera
    INTCON2bits.INTEDG0 = 0;
    //INTCON2bits.INTEDG1 = 0; // Flanco de bajada
    //INTCON3bits.INT1IP = 0;
    RCONbits.IPEN = 1; // Habilitando todas prioridades
    INTCONbits.GIEL = 1; // Habilitando prioridades bajadas
    INTCONbits.GIEH = 1; // Habilitamos prioridades altas
}

void __interrupt(high_priority) INT0_ISR(void){
    if(y == 0){
        x = 1;
        T0CONbits.TMR0ON = 1;
        y++;
    }
    else{
        x = 3;
        T0CONbits.TMR0ON = 0;
        y = 0;
    }
    
    INTCONbits.INT0IF = 0;
}

void __interrupt(low_priority) TMR0_ISR(void){
    a++;
    b++;
    if(a >= 100){
        LATDbits.LATD0 = ~LATDbits.LATD0;
        a = 0;
    }
    if(b >= 1000){
        x = 2;
        b = 0;
    }
    TMR0L = 236;
    INTCONbits.TMR0IF =0;
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


#include <xc.h>
#include "Configuracion.h"
#include "Timer0_8bit.h"
#include "Int_Libreria.h"

//void Timer0_Init(void){
//    T0CONbits.T0CS = 0; // Modo Temporizador
//    T0CONbits.T08BIT = 0; // 16 bits
//    T0CONbits.PSA = 0; // Asignamos Prescaler
//    T0CONbits.T0PS = 0b111; //Prescaler 256
//    TMR0 = 46004;
//    INTCONbits.TMR0IE = 1; // Habilitando TMR0 int
//    INTCONbits.TMR0IF = 0; //Bandera TMR0
//    INTCON2bits.TMR0IP = 0; //Prioridad baja
//    T0CONbits.TMR0ON = 1;
//
//}

void Timer0_Init(void){
    T0CONbits.T0CS = 0; // Modo Temporizador
    T0CONbits.T08BIT = 1; // 8 bits
    T0CONbits.PSA = 0; // Asignamos Prescaler
    T0CONbits.T0PS = 0b111; //Prescaler 256
    TMR0L = 236;
    INTCONbits.TMR0IE = 1; // Habilitando TMR0 int
    INTCONbits.TMR0IF = 0; //Bandera TMR0
    INTCON2bits.TMR0IP = 0; //Prioridad baja
    T0CONbits.TMR0ON = 1;

}


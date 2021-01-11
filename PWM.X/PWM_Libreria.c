
#include <xc.h>
#include "Configuracion.h"
#include "PWM_Libreria.h"
/*
 * CCPR1L = 0b00000101;//40% 00000101 01
 * CCP1CONbits.DC1B = 0b01;
 */


void PWM_Init(void){
    PR2 = 12; // PERIODO 1/24KHz
    CCPR1L = 0x00;//40% 00000101 01
    CCP1CONbits.DC1B = 0b00;
    TRISCbits.RC2 = 0; //Salida
    T2CONbits.T2CKPS = 0b10;// Prescaler 16
    T2CONbits.TMR2ON = 1; //TIMER 2 on
    CCP1CONbits.CCP1M = 0b1100; //Habilitando modo PWM
    
}

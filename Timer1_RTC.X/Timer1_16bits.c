
#include <xc.h>
#include "Timer1_16bits.h"
#include "Configuracion.h"
#include "Int_Libreria.h"

void Timer1_Init(void){
    TMR1H = 0x80;
    TMR1L = 0x00;
    T1CON = 0x0F;
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    IPR1bits.TMR1IP = 0;
}
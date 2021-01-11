
#include <xc.h>
#include "ADC_Libreria.h"
#include "Configuracion.h"

void ADC_Init(void){
    ADCON1bits.VCFG = 0b00; // Vss y Vdd
    ADCON1bits.PCFG = 0b1011;// AN0 RA0
    //ADCON0bits.CHS = 0b0000; // Seleccionamos canal 0
    ADCON2bits.ADCS = 0b101; // 16Tosc = 0.8useg -> TAD
    ADCON2bits.ACQT = 0b010; // 4TAD = 4 * 0.8useg = 3.2useg > 2.45useg 
    ADCON2bits.ADFM = 1;
    ADCON0bits.ADON = 1; // ADC Habilitado
}

uint16_t ADC_Read(uint8_t ch){
    if(ch >= 13){
        ch = 0;
    }
    ADCON0bits.CHS = ch;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE == 1);// Realizando conversión
    return ADRES;
}


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Configuracion.h"
#include "Int_Libreria.h"
#include "LCD_4bits.h"
#include "ADC_Libreria.h"

uint8_t x = 0;
uint8_t y = 0;
// VIN = VALOR_ADC * RESOLUCION
float Vin = 0.0; // 24bits 
char datos[10];
uint16_t valor_adc = 0;


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

void __interrupt(high_priority) ADC_ISR(void){
    valor_adc = ADRES;
    Vin = valor_adc*(5.0/1023); //float = int*(float/int)
    sprintf(datos,"Es: %0.2f V",Vin); 
    LCD_XY(0,0);
    LCD_Cadena(datos);
    __delay_ms(100);
    PIR1bits.ADIF = 0;
    ADCON0bits.GO_DONE = 1;
}

void __interrupt(low_priority) TMR0_ISR(void){
    x++;
    if(x >= 100){
        LATDbits.LATD0 = ~LATDbits.LATD0;
        x = 0;
    }
    TMR0 = 236;
    INTCONbits.TMR0IF = 0;
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

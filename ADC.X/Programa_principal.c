/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Configuracion.h"
#include "ADC_Libreria.h"
#include "LCD_4bits.h"
#include "Int_Libreria.h"

// VIN = VALOR_ADC * RESOLUCION
float Vin = 0.0; // 24bits 
char datos[10];
uint16_t valor_adc = 0;
extern uint8_t x;

void main(void) {
    ADC_Init();
    INT_Init();
    LCD_Init();
    while(1){
        LCD_Comando(0x01);
        valor_adc = ADC_Read(0);
        Vin = valor_adc*(5.0/1023); //float = int*(float/int)
        sprintf(datos,"Es: %0.2f V",Vin); 
        LCD_XY(0,0);
        LCD_Cadena(datos);
        __delay_ms(100);
        
    }
    return;
}

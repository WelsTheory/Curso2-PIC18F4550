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
#include "Timer0_8bit.h"


extern uint8_t x;
extern uint8_t y;


void main(void) {
    ADC_Init();
    LCD_Init();
    Timer0_Init();
    INT_Init();
    while(1){
        

    }
    return;
}

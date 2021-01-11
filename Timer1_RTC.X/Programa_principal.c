/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "LCD_4bits.h"
#include "Timer1_16bits.h"
#include "Int_Libreria.h"

extern int sec, sec_d, min, min_d, hor, hor_d;

void main(void) {
    TRISD = 0x00;
    LCD_Init();
//    LATDbits.LATD0 = 1;
//    LCD_XY(1,8);
//    LCD_Caracter('W');
    LCD_XY(0,0);
    LCD_Cadena("Hora:");
    Timer1_Init();
    INT_Init();
    while(1){
        LCD_XY(1,5);
        LCD_Caracter(hor_d + '0');
        LCD_Caracter(hor + '0');
        LCD_Caracter(':');
        LCD_Caracter(min_d + '0');
        LCD_Caracter(min + '0');
        LCD_Caracter(':');
        LCD_Caracter(sec_d + '0');
        LCD_Caracter(sec + '0');
        __delay_ms(100);
        
    }
    return;
}

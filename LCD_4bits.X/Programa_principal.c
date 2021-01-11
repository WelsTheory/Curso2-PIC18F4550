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

void main(void) {
    LCD_Init();
    LATDbits.LATD0 = 1;
    LCD_XY(1,8);
    LCD_Caracter('W');
    LCD_XY(0,0);
    LCD_Cadena("microchip");
    while(1){
        
    }
    return;
}

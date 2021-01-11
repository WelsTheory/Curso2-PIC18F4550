/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Int_Libreria.h"
#include "LCD_4bits.h"
#include "PWM_Libreria.h"
#include "Timer0_8bit.h"

uint8_t x = 0;

void main(void) {
    ADCON1bits.PCFG = 0xF;
    TRISB = 0xFF;
    TRISD = 0x00;
    LCD_Init();
    INT_Init();
    Timer0_Init();
    PWM_Init();
    while(1){
        if(x == 1){
            LCD_XY(0,0);
            LCD_Cadena("Bienvenidos!");
        }
        if(x == 2){
            LCD_Comando(LCD_Borrar);
            LCD_XY(0,0);
            LCD_Cadena("ACTIVAMOS PWM!");
            T2CONbits.TMR2ON = 1;
            x = 0;
        }
        if(x == 3){
            T2CONbits.TMR2ON = 0;
            LCD_XY(0,0);
            LCD_Cadena("APAGADO PWM :C!");
            LCD_XY(1,0);
            LCD_Cadena("Acaboooo!");
            __delay_ms(500);
            x = 4;
        }
        if(x == 4){
            LCD_Comando(LCD_Borrar);
            break;
        }
        
    }
    return;
}

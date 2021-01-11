/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "PWM_Libreria.h"
#include "Int_Libreria.h"

uint16_t duty = 0;
extern uint8_t x;
/*
 * CCPR1L = 0b00000101;//40% 00000101 01
 * CCP1CONbits.DC1B = 0b01;
 * CCPR1L 00001101 CCP1CONbits.DC1B 00 100%
 * 0000110100 
 */

void main(void) {
    PWM_Init();
    INT_Init();
    while(1){
        if(x == 1){
            duty++;
            if(duty >= 52){//00110100 100%
                duty = 51;
            }
            __delay_ms(20);
        }
        else{
            duty--;
            if(duty <= 0b00000000){
                duty = 0b00000001;
            }
            __delay_ms(20);
        }
        CCPR1L = duty>>2; //00001100 11
        CCP1CON = (CCP1CON&0x0F) | (duty<<4);//0b00110000
        __delay_ms(20);
    }
    return;
}
        /*
         * DUTY = 0b00110000
         * CCP1 = 0B00111100 AND 0X0F
         *        0B00001111
         *        0B00001100
         * OR     0B00110000
         *        0B0011 1100
         * 
         */

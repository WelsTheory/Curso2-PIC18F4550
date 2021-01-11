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

unsigned char display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
//unsigned char display[10]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
uint8_t uni = 0, dec = 0, cen = 0;
extern uint8_t x;

void main(void) {
    TRISD = 0x00;
    TRISA = 0x00;
    INT_Init();
    while(1){
        if(x == 1){
            LATAbits.LA0 = 1;
            LATD = display[4];
            __delay_ms(100);
            LATAbits.LA0 = 0;
        }
        if(x == 2){
            LATAbits.LA2 = 1;
            LATD = display[4];
            __delay_ms(500);
            LATAbits.LA2 = 0;
        }
//        for(int i = 0;i<999;i++){
//            cen = i/100;
//            LATAbits.LA0 = 1;
//            LATD = display[cen];
//            __delay_ms(20);
//            LATAbits.LA0 = 0;
//            LATAbits.LA1 = 1;
//            dec = i/10;
//            if(dec >= 10){
//                dec = dec%10;
//            }
//            LATD = display[dec];
//            __delay_ms(20);
//            uni = i%10; 
//            LATAbits.LA1 = 0;
//            LATAbits.LA2 = 1;
//            LATD = display[uni];
//            __delay_ms(20);
//            LATAbits.LA2 = 0;
//        }
    }
    return;
}

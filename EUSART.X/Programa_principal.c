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
#include "EUSART.h"
#include "Int_Libreria.h"
#include "LCD_4bits.h"
#include "ADC_Libreria.h"

char valor = 0;
extern char rec[4];
extern uint8_t x;
float Vin = 0.0; // 24bits 
char datos[10];
uint16_t valor_adc = 0;

void main(void) {
    EUSART_Init(31);//9600
    LCD_Init();
    INT_Init();
    ADC_Init();
    TRISD = 0x00;
    while(1){
        if(x == 4){
            LCD_XY(0,0);
            LCD_Cadena(rec);
            __delay_ms(100);
            x++;
        }
        if(x == 5){
            valor_adc = ADC_Read(0);
            Vin = valor_adc*(5.0/1023); //float = int*(float/int)
            sprintf(datos," Es: %0.2f V ",Vin); 
            EUSART_Cadena(datos);
            __delay_ms(100);
        }
    }
    return;
}

//void main(void) {
//    EUSART_Init(31);//9600
//    TRISD = 0x00;
//    while(1){
//        valor = EUSART_Rx();// 
//        switch(valor){
//            case '1':
//                EUSART_Cadena("Como estas?");
//                LATDbits.LATD0 = 1;
//                __delay_ms(200);
//                break;
//            case '2':
//                EUSART_Tx('N');
//                LATDbits.LATD0 = 0;
//                __delay_ms(200);
//                break;
//            case '3':
//                EUSART_Tx('A');
//                LATDbits.LATD1 = 1;
//                __delay_ms(200);
//                break;
//            default:
//                EUSART_Tx('S');
//                LATDbits.LATD1 = 0;
//                __delay_ms(200);
//                break;
//        }  
//    }
//    return;
//}

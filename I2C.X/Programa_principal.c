/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 11 de enero de 2021, 07:48 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "I2C_Libreria.h"
#include "DS1307_Libreria.h"
#include "LCD_4bits.h"

extern uint8_t segundos,minutos, horas;

void main(void) {
    I2C_Init();
    LCD_Init();
    TRISD = 0x00;
    //__delay_ms(1000);
    Escribir_Hora();
    LCD_XY(0,0);
    LCD_Cadena("LA hora es:");
    while(1){
        Leer_Hora();
        LCD_XY(1,0);
        /*12 horas 0xF0 >>4 | 0X01 OR 0x30 
         */
        LCD_Caracter(((horas&0xF0)>>4) + '0');
        LCD_Caracter((horas&0x0F) + '0');
        LCD_Caracter(':');
        LCD_Caracter(((minutos&0xF0)>>4) + '0');
        LCD_Caracter((minutos&0x0F) + '0');
        LCD_Caracter(':');
        LCD_Caracter(((segundos&0xF0)>>4) + '0');
        LCD_Caracter((segundos&0x0F) + '0');
        __delay_ms(100);      
    }
    return;
}

//        for(uint8_t i = 0;i<16;i++){
//            I2C_Start();
//            I2C_Tx(0x40);// Dir + RW 
//            I2C_ACK();
//            I2C_Tx(i);
//            I2C_ACK();
//            I2C_Stop();
//            __delay_ms(100);
//        }
//        I2C_Start();
//        I2C_Tx(0x41);// Dir + RW 
//        I2C_ACK();
//        LATD = I2C_Rx();
//        //I2C_ACK();
//        I2C_Stop();
//        __delay_ms(100);

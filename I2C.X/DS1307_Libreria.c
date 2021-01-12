
#include <xc.h>
#include "Configuracion.h"
#include "DS1307_Libreria.h"
#include "I2C_Libreria.h"

char set[6] = "235957";
uint8_t horas = 0, segundos = 0, minutos = 0,fecha=0;

void Escribir_Hora(void){
    /*
     * horas_d = (0x31 & 0x0F) = 0x01 <<4 = 0x10
     *  12
     */ 
    horas = ((set[0] & 0x0F)<<4) | (set[1] & 0x0F);
    /*
     *    = 0x10 OR 0X02 = 0X12     
     */
    minutos = ((set[2] & 0x0F)<<4) | (set[3] & 0x0F);
    segundos = ((set[4] & 0x0F)<<4) | (set[5] & 0x0F);
    I2C_Start();
    I2C_Tx(0b11010000);
    I2C_ACK();
    I2C_Tx(0b00000000);// COMIENZA DESDE SEG
    I2C_Tx(segundos);
    I2C_Tx(minutos);
    I2C_Tx(horas);
    I2C_Stop();
}

void Leer_Hora(void){
    I2C_Start();
    I2C_Tx(0b11010000);
    I2C_ACK();
    I2C_Tx(0b00000000);// COMIENZA DESDE SEG
    I2C_Restart();
    I2C_Tx(0b11010001);//leer datos
    I2C_ACK();
    segundos = I2C_Rx();
    I2C_ACK();
    minutos = I2C_Rx();
    I2C_ACK();
    horas = I2C_Rx();//12 + 0x31 + 0x32
    I2C_NACK();
    I2C_Stop();
}


//void Leer_Hora(void);
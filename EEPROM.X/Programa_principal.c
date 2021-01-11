/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de diciembre de 2020, 08:17 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

void main(void) {
    TRISD = 0x00;
    LATD = 0x00;
    EEPROM_Write(0xFF,0xFF);
    LATD = EEPROM_Read(255);
    __delay_ms(500);
    EEPROM_Write(0xFF,0x00);
    LATD = EEPROM_Read(255);
    while(1){
        
    }
    return;
}

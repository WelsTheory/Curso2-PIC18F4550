
#include <xc.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

void EEPROM_Write(char dir, char dato){
    EEADR = dir;
    EEDATA = dato;
    EECON1bits.CFGS = 0;// EEPROM Configuracion
    EECON1bits.EEPGD = 0;// EEPROM
    EECON1bits.WREN = 1; //Habilitamos la escritura
    EECON2 = 0x55;// Paso Requerido
    EECON2 = 0xAA;// Paso Requerido
    EECON1bits.WR = 1; // Iniciar la escritura
    while(EECON1bits.WR == 1); //Aún no termina de escribir
    EECON1bits.WREN = 0;

}

char EEPROM_Read(char dir){
    EEADR = dir;
    EECON1bits.CFGS = 0;// EEPROM Configuracion
    EECON1bits.EEPGD = 0;// EEPROM
    EECON1bits.RD = 1;// Inicia la lectura
    return EEDATA;
}

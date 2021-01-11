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
#include "Timer0_8bit.h"

void main(void) {
    TRISD = 0x00;
    Timer0_Init();
    INT_Init();
    while(1){
        
    }
    return;
}


#include <xc.h>
#include "Configuracion.h"
#include "EUSART.h"

void EUSART_Init(uint8_t baud){
    SPBRG = baud ;//9600
    TXSTAbits.BRGH = 0;
    BAUDCONbits.BRG16 = 0;
    TXSTAbits.SYNC = 0; // Asincrono
    RCSTAbits.SPEN = 1;// TX y RX
    //Transmisión
    TXSTAbits.TX9 = 0;// 8 bits
    TXSTAbits.TXEN = 1; //Habilitamos Tx
    //Recepción
    RCSTAbits.RX9 = 0;//8 bits
    RCSTAbits.CREN = 1;// Habiliatar Rx
    //Habiliat Int
    PIR1bits.RCIF = 0;//Limpiamos Int
    PIE1bits.RCIE = 1; //Habiliat int RX
    IPR1bits.RCIP = 1;//Baja prioridad
}

void EUSART_Tx(char data){
    while(TXSTAbits.TRMT == 0);
    TXREG = data;
}

char EUSART_Rx(void){
    return RCREG;
}

void EUSART_Cadena(char *datas){
    while(*datas != '\0'){
        EUSART_Tx(*datas);
        datas++;
    }
}

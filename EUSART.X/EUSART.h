

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EUSART_H
#define	EUSART_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void EUSART_Init(uint8_t baud);
void EUSART_Tx(char data);
char EUSART_Rx(void);
void EUSART_Cadena(char *datas);

#endif	/* XC_HEADER_TEMPLATE_H */


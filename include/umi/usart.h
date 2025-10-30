#ifndef UMI_USART_H
#define UMI_USART_H

#include <avr/io.h>
#include <umi/utils.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

void USARTInit(void);
uint8_t USARTReceive();
void USARTTransmit(uint8_t data);
void USARTTransmitStr(uint8_t *str);

#endif  // UMI_USART_H

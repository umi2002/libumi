#ifndef UMI_USART_H
#define UMI_USART_H

#include <avr/io.h>
#include <umi/utils.h>

void USARTInit(void);
void USARTTransmit(uint8_t data);
void USARTTransmitStr(uint8_t *str);

#endif  // UMI_USART_H

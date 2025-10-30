#include "umi/usart.h"

#include "umi/utils.h"

void USARTInit() {
  // Set baud rate using calculated UBRR value
  UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
  UBRR0L = (uint8_t)(UBRR_VALUE);

  // Enable transmitter
  setPin(&UCSR0B, TXEN0);
  // Enable Receiver
  setPin(&UCSR0B, RXEN0);

  // Frame format: 8 data, 1 stop bit
  clearPin(&UCSR0C, USBS0);
  setPin(&UCSR0C, UCSZ00);
  setPin(&UCSR0C, UCSZ01);
  clearPin(&UCSR0B, UCSZ02);
}

uint8_t USARTReceive() {
  // Wait for data to be received
  while (!readPin(&UCSR0A, RXC0));

  // Return data from buffer
  return UDR0;
}

void USARTTransmit(uint8_t data) {
  // Wait for empty transmit buffer
  while (!readPin(&UCSR0A, UDRE0));

  // Put data into buffer, sends the data
  UDR0 = data;
}

void USARTTransmitStr(uint8_t *str) {
  uint8_t index = 0;

  while (str[index] != '\0') {
    USARTTransmit(str[index]);
    index++;
  }
}

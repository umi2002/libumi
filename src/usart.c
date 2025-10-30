#include "umi/usart.h"

void USARTInit() {
  // Baud rate = 9600 at F_OSC = 16MHz, normal speed
  UBRR0H = (uint8_t)(103 >> 8);
  UBRR0L = (uint8_t)(103);

  // Enable transmitter
  setPin(&UCSR0B, TXEN0);
  setPin(&UCSR0B, RXEN0);

  // Frame format: 8 data, 1 stop bit
  clearPin(&UCSR0C, USBS0);
  setPin(&UCSR0C, UCSZ00);
  setPin(&UCSR0C, UCSZ01);
  clearPin(&UCSR0B, UCSZ02);
}

void USARTTransmit(uint8_t data) {
  // Wait for empty transmit buffer
  while (!(UCSR0A & (1 << UDRE0)));

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

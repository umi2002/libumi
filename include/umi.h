#include <avr/io.h>

// utils.c
void setPin(volatile uint8_t *reg, uint8_t pin);
void clearPin(volatile uint8_t *reg, uint8_t pin);
uint8_t readPin(volatile uint8_t *reg, uint8_t pin);
void maskWrite(volatile uint8_t *reg, uint8_t mask, uint8_t value);

// usart.c
void USARTInit();
void USARTTransmit(uint8_t data);

// eeprom.c
void EEPROMwrite(uint16_t address, uint8_t data);
uint8_t EEPROMread(uint16_t address);

// keypad.c
void keypadInit();
uint8_t scanKeypad();

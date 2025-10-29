#include <avr/io.h>
#include <util/delay.h>

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
void USARTTransmitStr(uint8_t *str);

// keypad.c
void keypadInit();
uint8_t scanKeypad();

// lcd.c
void pulseEnablePin();

uint8_t readBusyFlag();

void writeInstruction4b(uint8_t instruction);

void writeData4b(uint8_t instruction);

void LCDInit4b();

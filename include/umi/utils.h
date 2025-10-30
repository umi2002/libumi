#ifndef UMI_UTILS_H
#define UMI_UTILS_H

#include <avr/io.h>

void setPin(volatile uint8_t *reg, uint8_t pin);
void clearPin(volatile uint8_t *reg, uint8_t pin);
uint8_t readPin(volatile uint8_t *reg, uint8_t pin);
void maskWrite(volatile uint8_t *reg, uint8_t mask, uint8_t value);

#endif  // UMI_UTILS_H

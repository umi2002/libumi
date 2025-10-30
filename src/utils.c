#include "umi/utils.h"

void setPin(volatile uint8_t *reg, uint8_t pin) { *reg |= (1 << pin); }

void clearPin(volatile uint8_t *reg, uint8_t pin) { *reg &= ~(1 << pin); }

uint8_t readPin(volatile uint8_t *reg, uint8_t pin) {
  return (*reg & (1 << pin)) ? 1 : 0;
}

void maskWrite(volatile uint8_t *reg, uint8_t mask, uint8_t value) {
  uint8_t tmp = *reg;
  tmp &= ~mask;
  tmp |= value & mask;
  *reg = tmp;
}

#include "umi.h"

void setPin(volatile uint8_t *reg, uint8_t pin)
{
    *reg |= (1 << pin);
}

void clearPin(volatile uint8_t *reg, uint8_t pin)
{
    *reg &= ~(1 << pin);
}

uint8_t readPin(volatile uint8_t *reg, uint8_t pin)
{
    return *reg & (1 << pin);
}

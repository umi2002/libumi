#include "umi.h"

void setPin(volatile uint8_t *reg, uint8_t pin)
{
    *reg |= (1 << pin);
}

void clearPin(volatile uint8_t *reg, uint8_t pin)
{
    *reg &= ~(1 << pin);
}

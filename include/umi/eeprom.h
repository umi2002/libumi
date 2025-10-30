#ifndef UMI_EEPROM_H
#define UMI_EEPROM_H

#include <avr/io.h>
#include <umi/utils.h>
#include <util/delay.h>

void EEPROMwrite(uint16_t address, uint8_t data);
uint8_t EEPROMread(uint16_t address);

#endif  // UMI_EEPROM_H

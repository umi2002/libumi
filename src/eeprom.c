#include "umi.h"

void EEPROMwrite(uint16_t address, uint8_t data) {
  /* Wait for completion of previous write */
  while (EECR & (1 << EEPE));
  /* Set up address and Data Registers */
  EEAR = address;
  EEDR = data;
  /* Start eeprom write by setting EEMPE and EEPE */
  setPin(&EECR, EEMPE);
  setPin(&EECR, EEPE);
}

uint8_t EEPROMread(uint16_t address) {
  /* Wait for completion of previous write */
  while (EECR & (1 << EEPE));
  /* Set up address register */
  EEAR = address;
  /* Start eeprom read by writing EERE */
  setPin(&EECR, EERE);
  /* Return data from Data Register */
  return EEDR;
}

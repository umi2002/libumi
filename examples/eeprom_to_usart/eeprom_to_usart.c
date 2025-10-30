#include <umi/eeprom.h>
#include <umi/usart.h>

int main() {
  USARTInit();

  for (uint16_t address = 0; address < EEPROM_SIZE; address++) {
    uint8_t value = EEPROMread(address);
    USARTTransmit(value);
  }

  while (1);

  return 0;
}

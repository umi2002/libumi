#include <umi/eeprom.h>
#include <umi/usart.h>

int main() {
  USARTInit();

  uint16_t address = 0;

  while (1) {
    uint8_t value = USARTReceive();
    EEPROMwrite((address++ % EEPROM_SIZE), value);
  }

  return 0;
}

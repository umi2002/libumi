#include <umi/eeprom.h>
#include <umi/usart.h>

int main() {
  USARTInit();

  uint8_t message[] = "This is a message from the eeprom!\n";

  for (uint8_t i = 0; i < sizeof(message) / sizeof(message[0]); i++) {
    EEPROMwrite(i, message[i]);
  }

  for (uint8_t i = 0; i < sizeof(message) / sizeof(message[0]); i++) {
    uint8_t value = EEPROMread(i);
    USARTTransmit(value);
  }

  return 0;
}

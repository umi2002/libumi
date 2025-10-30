#include <umi/keypad.h>
#include <umi/usart.h>

int main() {
  USARTInit();
  keypadInit();

  uint8_t initString[] = "Keypad USART example started!\n";
  USARTTransmitStr(initString);

  while (1) {
    uint8_t key = scanKeypad();
    USARTTransmit(key);
  }

  return 0;
}

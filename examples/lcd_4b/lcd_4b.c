#include <umi/lcd.h>

int main() {
  LCDInit4b();

  uint8_t message[] = "LCD works!";

  for (uint8_t i = 0; message[i] != '\0'; i++) {
    while (readBusyFlag());
    writeData4b(message[i]);
  }

  while (1);

  return 0;
}

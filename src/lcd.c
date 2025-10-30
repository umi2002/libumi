#include "umi/lcd.h"

void pulseEnablePin() {
  _delay_us(1);
  clearPin(&PORTC, PC0);
  _delay_us(1);
  setPin(&PORTC, PC0);
  _delay_us(1);
  clearPin(&PORTC, PC0);
  _delay_us(1);
}

uint8_t readBusyFlag() {
  // RS = 0, R/W = 1 : Read busy flag
  clearPin(&PORTC, PC2);
  setPin(&PORTC, PC1);

  // Set D7 pin as input
  clearPin(&DDRD, PD7);
  // Hold E pin while reading busy flag
  setPin(&PORTC, PC0);
  _delay_us(1);

  uint8_t busyFlag = readPin(&PIND, PD7);

  // Clear E pin after reading busy flag
  setPin(&DDRD, PD7);
  // Revert D7 pin to output
  clearPin(&PORTC, PC0);
  _delay_us(1);

  // Pulse E pin for synchronizing 4 bit format
  pulseEnablePin();

  return busyFlag;
}

void writeInstruction4b(uint8_t instruction) {
  // RS = 0, R/W = 0 : Write instruction
  clearPin(&PORTC, PC2);
  clearPin(&PORTC, PC1);

  // Write upper nibble
  maskWrite(&PORTD, UPPER_NIBBLE_MASK, instruction);
  pulseEnablePin();

  // Write lower nibble
  maskWrite(&PORTD, UPPER_NIBBLE_MASK,
            (instruction & LOWER_NIBBLE_MASK) << NIBBLE_SIZE);
  pulseEnablePin();
}

void writeData4b(uint8_t instruction) {
  // RS = 1, R/W = 0 : Write data
  setPin(&PORTC, PC2);
  clearPin(&PORTC, PC1);

  // Write upper nibble
  maskWrite(&PORTD, UPPER_NIBBLE_MASK, instruction);
  pulseEnablePin();

  // Write lower nibble
  maskWrite(&PORTD, UPPER_NIBBLE_MASK,
            (instruction & LOWER_NIBBLE_MASK) << NIBBLE_SIZE);
  pulseEnablePin();
}

void LCDInit4b() {
  // Set PD4-PD7, PC0-PC2 pins as output
  setPin(&DDRD, PD4);
  setPin(&DDRD, PD5);
  setPin(&DDRD, PD6);
  setPin(&DDRD, PD7);
  setPin(&DDRC, PC0);
  setPin(&DDRC, PC1);
  setPin(&DDRC, PC2);

  _delay_ms(LCD_INIT_DELAY_POWER_ON_MS_5V);

  // E = 0, RS = 0, R/W = 0
  clearPin(&PORTC, PC2);
  clearPin(&PORTC, PC1);
  clearPin(&PORTC, PC0);
  _delay_us(1);

  /* Initialization sequence as instructed by HD44780 datasheet:
  https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf
  Busy flag is not ready during this sequence */

  maskWrite(&PORTD, UPPER_NIBBLE_MASK, LCD_INIT);
  pulseEnablePin();
  _delay_ms(LCD_INIT_DELAY_MS);

  maskWrite(&PORTD, UPPER_NIBBLE_MASK, LCD_INIT);
  pulseEnablePin();
  _delay_ms(LCD_INIT_DELAY_MS);

  maskWrite(&PORTD, UPPER_NIBBLE_MASK, LCD_INIT);
  pulseEnablePin();
  _delay_ms(LCD_INIT_DELAY_MS);

  maskWrite(&PORTD, UPPER_NIBBLE_MASK, LCD_FUNCTION_SET_4B);
  pulseEnablePin();
  _delay_us(FUNCTION_SET_DELAY_US);

  writeInstruction4b(LCD_FUNCTION_SET_4B | LCD_FUNCTION_SET_2_LINES |
                     LCD_FUNCTION_SET_5X8);
  _delay_us(FUNCTION_SET_DELAY_US);

  writeInstruction4b(LCD_DISPLAY_CONTROL | LCD_DISPLAY_OFF | LCD_CURSOR_OFF |
                     LCD_BLINK_OFF);
  _delay_us(DISPLAY_CONTROL_DELAY_US);

  writeInstruction4b(LCD_CLEAR_DISPLAY);
  _delay_ms(CLEAR_DISPLAY_DELAY_MS);

  writeInstruction4b(LCD_ENTRY_MODE_SET | LCD_ENTRY_MODE_INCREMENT |
                     LCD_ENTRY_MODE_NO_SHIFT);
  _delay_ms(ENTRY_MODE_SET_DELAY_US);

  // End of initialization sequence. Busy flag is now ready.

  while (readBusyFlag());
  writeInstruction4b(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_ON |
                     LCD_BLINK_ON);
}

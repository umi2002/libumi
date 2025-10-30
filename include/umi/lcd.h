#ifndef UMI_LCD_H
#define UMI_LCD_H

#include <avr/io.h>
#include <umi/utils.h>
#include <util/delay.h>

#define LCD_INIT_DELAY_POWER_ON_MS_5V 50
#define LCD_INIT_DELAY_MS 5
#define FUNCTION_SET_DELAY_US 50
#define DISPLAY_CONTROL_DELAY_US 50
#define CLEAR_DISPLAY_DELAY_MS 2
#define ENTRY_MODE_SET_DELAY_US 50

#define NIBBLE_SIZE 4
#define UPPER_NIBBLE_MASK 0xF0
#define LOWER_NIBBLE_MASK 0x0F
#define LCD_INIT 0x30

#define LCD_FUNCTION_SET_4B 0x20
#define LCD_FUNCTION_SET_1_LINE 0x00
#define LCD_FUNCTION_SET_2_LINES 0x08
#define LCD_FUNCTION_SET_5X8 0x00
#define LCD_FUNCTION_SET_5X10 0x04

#define LCD_DISPLAY_CONTROL 0x08
#define LCD_DISPLAY_OFF 0x00
#define LCD_DISPLAY_ON 0x04
#define LCD_CURSOR_OFF 0x00
#define LCD_CURSOR_ON 0x02
#define LCD_BLINK_OFF 0x00
#define LCD_BLINK_ON 0x01

#define LCD_ENTRY_MODE_SET 0x04
#define LCD_ENTRY_MODE_DECREMENT 0x00
#define LCD_ENTRY_MODE_INCREMENT 0x02
#define LCD_ENTRY_MODE_NO_SHIFT 0x00
#define LCD_ENTRY_MODE_SHIFT 0x01

#define LCD_CURSOR_SHIFT 0x10
#define LCD_DISPLAY_SHIFT 0x18
#define SHIFT_LEFT 0x00
#define SHIFT_RIGHT 0x04

#define LCD_RETURN_HOME 0x02
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

void pulseEnablePin(void);
uint8_t readBusyFlag(void);
void writeInstruction4b(uint8_t instruction);
void writeData4b(uint8_t instruction);
void LCDInit4b(void);

#endif  // UMI_LCD_H

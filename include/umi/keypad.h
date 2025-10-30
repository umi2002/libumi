#ifndef UMI_KEYPAD_H
#define UMI_KEYPAD_H

#include <avr/io.h>
#include <umi/utils.h>

void keypadInit(void);
uint8_t scanKeypad(void);

#endif  // UMI_KEYPAD_H

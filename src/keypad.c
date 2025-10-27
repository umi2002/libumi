#include "umi.h"

#define N_ROWS 4
#define N_COLS 4

const char KEYPAD[N_ROWS][N_COLS] = {{'1', '2', '3', 'A'},
                                     {'4', '5', '6', 'B'},
                                     {'7', '8', '9', 'C'},
                                     {'*', '0', '#', 'D'}};

void keypadInit() {
  setPin(&DDRB, PB0);
  setPin(&DDRB, PB1);
  clearPin(&DDRD, PD2);
  clearPin(&DDRD, PD3);
  clearPin(&DDRD, PD4);
  clearPin(&DDRD, PD5);
  setPin(&DDRD, PD6);
  setPin(&DDRD, PD7);

  setPin(&PORTD, PD2);
  setPin(&PORTD, PD3);
  setPin(&PORTD, PD4);
  setPin(&PORTD, PD5);
}

static void selectRow(uint8_t row) {
  setPin(&PORTB, PB0);
  setPin(&PORTB, PB1);
  setPin(&PORTD, PD6);
  setPin(&PORTD, PD7);

  switch (row) {
    case 0:
      clearPin(&PORTB, PB1);
      break;
    case 1:
      clearPin(&PORTB, PB0);
      break;
    case 2:
      clearPin(&PORTD, PD7);
      break;
    case 3:
      clearPin(&PORTD, PD6);
      break;
  }
}

static uint8_t scanColumns() {
  if (!(readPin(&PIND, PD5))) {
    return 1;
  } else if (!(readPin(&PIND, PD4))) {
    return 2;
  } else if (!(readPin(&PIND, PD3))) {
    return 3;
  } else if (!(readPin(&PIND, PD2))) {
    return 4;
  }

  return 0;
}

uint8_t scanKeypad() {
  for (uint8_t i = 0; i < N_ROWS; i++) {
    selectRow(i);
    uint8_t col = scanColumns();

    if (col) {
      return KEYPAD[i][col - 1];
    }
  }

  return 0;
}

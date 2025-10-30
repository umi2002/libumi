# Hardware Setup Guide

This guide covers the wiring and pin configurations for all libumi modules.

## Table of Contents

- [ATmega328P Pinout](#atmega328p-pinout)
- [LCD Display (16x2)](#lcd-display-16x2)
- [4x4 Matrix Keypad](#4x4-matrix-keypad)
- [USART Serial](#usart-serial)

---

## ATmega328P Pinout

https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#G1176667

---

## LCD Display (16x2)

### HD44780-Compatible LCD Wiring (4-bit Mode)

```
Arduino UNO          LCD Module (HD44780)
-----------          --------------------
    5V      -------> VSS (Pin 1)  - Ground
    GND     -------> VDD (Pin 2)  - Power (+5V)
    (POT)   -------> V0  (Pin 3)  - Contrast (via 10kΩ pot)
    A2      -------> RS  (Pin 4)  - Register Select
    A1      -------> RW  (Pin 5)  - Read/Write
    A0      -------> E   (Pin 6)  - Enable
                     D0  (Pin 7)  - Not connected
                     D1  (Pin 8)  - Not connected
                     D2  (Pin 9)  - Not connected
                     D3  (Pin 10) - Not connected
    D4      -------> D4  (Pin 11) - Data bit 4
    D5      -------> D5  (Pin 12) - Data bit 5
    D6      -------> D6  (Pin 13) - Data bit 6
    D7      -------> D7  (Pin 14) - Data bit 7
    5V      -------> A   (Pin 15) - Backlight Anode (+)
    GND     -------> K   (Pin 16) - Backlight Cathode (-)
```

### Pin Configuration

| Signal | ATmega Pin | Arduino Pin | Function            |
| ------ | ---------- | ----------- | ------------------- |
| RS     | PC2        | A2          | Register Select     |
| RW     | PC1        | A1          | Read/Write (or GND) |
| E      | PC0        | A0          | Enable              |
| DB4    | PD4        | D4          | Data Bit 4          |
| DB5    | PD5        | D5          | Data Bit 5          |
| DB6    | PD6        | D6          | Data Bit 6          |
| DB7    | PD7        | D7          | Data Bit 7          |

### Contrast Adjustment

Connect a 10kΩ potentiometer:

- Left pin → 5V
- Middle pin → LCD V0 (contrast)
- Right pin → GND

Adjust the potentiometer to see clear characters on the display.

---

## 4x4 Matrix Keypad

### Keypad Layout

```
      COL0  COL1  COL2  COL3
       |     |     |     |
ROW0--[1]---[2]---[3]---[A]
       |     |     |     |
ROW1--[4]---[5]---[6]---[B]
       |     |     |     |
ROW2--[7]---[8]---[9]---[C]
       |     |     |     |
ROW3--[*]---[0]---[#]---[D]
```

### Pin Configuration

| Keypad Pin | ATmega Pin | Arduino Pin | Function                    |
| ---------- | ---------- | ----------- | --------------------------- |
| ROW0       | PB1        | D9          | Row 0 (Output)              |
| ROW1       | PB0        | D8          | Row 1 (Output)              |
| ROW2       | PD7        | D7          | Row 2 (Output)              |
| ROW3       | PD6        | D6          | Row 3 (Output)              |
| COL0       | PD5        | D5          | Column 0 (Input w/ pull-up) |
| COL1       | PD4        | D4          | Column 1 (Input w/ pull-up) |
| COL2       | PD3        | D3          | Column 2 (Input w/ pull-up) |
| COL3       | PD2        | D2          | Column 3 (Input w/ pull-up) |

### How It Works

1. Rows (PB1-PB2, PD6-PD7) are set as outputs
2. Columns (PD2-PD5) are set as inputs with internal pull-ups
3. To scan:
   - Set one row LOW at a time
   - Read all columns
   - If a column reads LOW, that key is pressed

---

## USART Serial

USART uses the built-in serial pins of the ATmega328P.

### Pin Configuration

| Signal | ATmega Pin | Arduino Pin | Function      |
| ------ | ---------- | ----------- | ------------- |
| RX     | PD0        | D0          | Receive Data  |
| TX     | PD1        | D1          | Transmit Data |

### Using with Arduino UNO

If programming via Arduino UNO, the USB is already connected to PD0/PD1, so no additional wiring is needed for serial communication.

### Monitoring Serial Output

#### Configuration

- Baud: 9600
- Data bits: 8
- Stop bits: 1
- Parity: None

**Bash:**

```bash
stty -F /dev/ttyACM0 \
  9600 \
  cs8 \
  -cstopb \
  -parenb \
  raw \

cat /dev/ttyACM0 9600
```

**Note:** It is recommended to use a serial monitoring software for ease of use.

---

## Additional Resources

- [Arduino UNO R3](https://docs.arduino.cc/hardware/uno-rev3/)
- [ATmega328P](https://www.microchip.com/wwwproducts/en/ATmega328P)
- [HD44780 LCD Controller Datasheet](https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf)

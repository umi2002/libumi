# libumi API Reference

Complete API documentation for all libumi modules.

## Table of Contents

- [Utilities](#utilities)
- [USART](#usart)
- [EEPROM](#eeprom)
- [Keypad](#keypad)
- [LCD](#lcd)

---

## Utilities

Low-level pin manipulation functions.

### `void setPin(volatile uint8_t *reg, uint8_t pin)`

Sets a specific bit in a register (sets pin HIGH).

**Parameters:**

- `reg`: Pointer to the register (e.g., `&PORTD`, `&DDRC`)
- `pin`: Pin number (0-7, use macros like `PD5`, `PC2`)

**Example:**

```c
setPin(&PORTD, PD5);  // Set PD5 HIGH
setPin(&DDRC, PC2);   // Set PC2 as OUTPUT
```

---

### `void clearPin(volatile uint8_t *reg, uint8_t pin)`

Clears a specific bit in a register (sets pin LOW).

**Parameters:**

- `reg`: Pointer to the register
- `pin`: Pin number

**Example:**

```c
clearPin(&PORTC, PC0);  // Set PC0 LOW
clearPin(&DDRD, PD3);   // Set PD3 as INPUT
```

---

### `uint8_t readPin(volatile uint8_t *reg, uint8_t pin)`

Reads the value of a specific bit in a register.

**Parameters:**

- `reg`: Pointer to the register (typically PIN register like `&PIND`)
- `pin`: Pin number

**Returns:**

- `1` if the pin is HIGH
- `0` if the pin is LOW

**Example:**

```c
uint8_t button = readPin(&PIND, PD2);
if (button) {
    // Button is pressed
}
```

---

### `void maskWrite(volatile uint8_t *reg, uint8_t mask, uint8_t value)`

Writes a value to specific bits in a register using a mask.

**Parameters:**

- `reg`: Pointer to the register
- `mask`: Bit mask indicating which bits to modify
- `value`: Value to write (only bits set in mask are affected)

**Example:**

```c
// Write 0x5 to upper nibble of PORTD (bits 4-7)
maskWrite(&PORTD, 0xF0, 0x50);  // Sets PD7=0, PD6=1, PD5=0, PD4=1
```

---

## USART

Serial communication interface.

### `void USARTInit()`

Initializes USART for serial communication at 9600 baud.

**Configuration:**

- Baud rate: 9600
- Data bits: 8
- Parity: None
- Stop bits: 1

**Example:**

```c
USARTInit();
```

---

### `uint8_t USARTReceive()`

Receives a single byte over USART. This operation is blocking.

**Returns:**

- Byte value received by USART

**Example:**

```c
uint8_t value = USARTReceive();
```

---

### `void USARTTransmit(uint8_t data)`

Transmits a single byte over USART.

**Parameters:**

- `data`: Byte to transmit

**Example:**

```c
USARTTransmit('A');      // Send character 'A'
USARTTransmit(0x42);     // Send byte 0x42 (decimal 66)
```

---

### `void USARTTransmitStr(uint8_t *str)`

Transmits a null-terminated string over USART.

**Parameters:**

- `str`: Pointer to null-terminated string

**Example:**

```c
USARTTransmitStr("Hello World!\n");

uint8_t buffer[] = "Temperature: 25C\n";
USARTTransmitStr(buffer);
```

---

## EEPROM

Non-volatile memory read/write operations.

### `void EEPROMwrite(uint16_t address, uint8_t data)`

Writes a byte to EEPROM.

**Parameters:**

- `address`: EEPROM address (0-1023)
- `data`: Byte to write

**Example:**

```c
EEPROMwrite(0, 42);        // Write 42 to address 0
EEPROMwrite(100, 0xFF);    // Write 0xFF to address 100
```

---

### `uint8_t EEPROMread(uint16_t address)`

Reads a byte from EEPROM.

**Parameters:**

- `address`: EEPROM address (0-1023)

**Returns:**

- Byte value at the specified address

**Example:**

```c
uint8_t value = EEPROMread(0);     // Read from address 0
uint8_t config = EEPROMread(100);  // Read from address 100
```

---

## Keypad

Matrix keypad scanning functions.

### `void keypadInit()`

Initializes the keypad matrix.

**Example:**

```c
keypadInit();
```

---

### `uint8_t scanKeypad()`

Scans the keypad matrix and returns the pressed key.

**Returns:**

- Keypad character as byte if a key is pressed
- `0x00` if no key is pressed

**Example:**

```c
uint8_t key = scanKeypad();
if (key) {
    // Key pressed, handle it
    if (key == '1') {
        // Key '1' pressed
    }
}
```

---

## LCD

[HD44780-compatible](https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf) LCD display control (4-bit mode).

### `void LCDInit4b()`

Initializes the LCD in 4-bit mode with 2 lines and 5x8 font.

**Example:**

```c
LCDInit4b();
```

**Note:** Initialization can last a few milliseconds.

---

### `void writeInstruction4b(uint8_t instruction)`

Sends a command instruction to the LCD.

**Parameters:**

- `instruction`: LCD command byte

**Example:**

```c
// Clear the display
while (readBusyFlag());
writeInstruction4b(0x01);

// Turn display on, cursor off, blink off
while (readBusyFlag());
writeInstruction4b(0x08 | 0x04 | 0x00 | 0x00);

// Move cursor to second line
while (readBusyFlag());
writeInstruction4b(0x80 | 0x40);  // Set DDRAM address to 0x40
```

---

### `void writeData4b(uint8_t data)`

Sends a character to be displayed on the LCD.

**Parameters:**

- `data`: ASCII character to display

**Example:**

```c
while (readBusyFlag());
writeData4b('H');     // Display 'H'
while (readBusyFlag());
writeData4b('i');     // Display 'i'
while (readBusyFlag());
writeData4b('!');     // Display '!'

// Display a string
uint8_t message[] = "Hello";
for (uint8_t i = 0; i < sizeof(message) / sizeof(message[i]); i++) {
    while (readBusyFlag());
    writeData4b(message[i]);
}
```

---

### `uint8_t readBusyFlag()`

Reads the LCD busy flag to determine if the LCD is ready.

**Returns:**

- `1` if LCD is busy
- `0` if LCD is ready

**Example:**

```c
// Wait for LCD to be ready
while (readBusyFlag());

// Now safe to send command/data
writeData4b('A');
```

**Note:** During initialization, delays are used as instructed by the [HD44780](https://cdn.sparkfun.com/assets/9/5/f/7/b/HD44780.pdf) datasheet instead of polling since the busy flag isn't ready yet.

---

### `void pulseEnablePin()`

Generates an enable pulse for LCD communication.

**Note:** This is a low-level function typically used internally. Use `writeInstruction4b()` and `writeData4b()` instead.

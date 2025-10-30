# libumi

My homebrew C library for AVR microcontrollers (ATmega328P) providing easy-to-use interfaces for common peripherals and components.

## Features

- **LCD Display**: 4-bit mode HD44780-compatible LCD control
- **USART**: Serial communication interface
- **EEPROM**: Non-volatile memory read/write operations
- **Keypad**: Matrix keypad scanning
- **Utilities**: Pin manipulation and bit masking helpers

## Hardware Requirements

- [Arduino UNO R3](https://docs.arduino.cc/hardware/uno-rev3/#tech-specs)
  - [ATmega328P microcontroller](https://www.microchip.com/en-us/product/atmega328p)

## Dependencies

- [avr-gcc](https://github.com/arduino/toolchain-avr)
- [avr-libc](https://github.com/avrdudes/avr-libc)
- [avrdude](https://github.com/avrdudes/avrdude)
- [GNU Make](https://www.gnu.org/software/make/)

## Quick Start

### Installation

```bash
# Clone the repository
git clone https://github.com/umi2002/libumi.git
cd libumi

# Build the library
make

# Install system-wide (requires superuser)
sudo make install
```

### Build an Example

```bash
cd examples/<example_directory_name>
make
make flash
```

## Documentation

- [Getting Started](docs/getting-started.md) - Installation and setup guide
- [API Reference](docs/api-reference.md) - Complete function documentation
- [Hardware Setup](docs/hardware-setup.md) - Pin configurations
- [Examples Overview](docs/examples.md) - Description of all examples

## Examples

- **lcd_4b** - 4-bit mode LCD display demonstration
- **keypad_usart** - Keypad input with serial output
- **eeprom_to_usart** - EEPROM read with serial interface
- **usart_to_eeprom** - EEPROM write with serial interface

## Usage

### Include All Modules

```c
#include <umi.h>
```

### Include Specific Modules

```c
#include <umi/usart.h>
#include <umi/lcd.h>
```

### Available Modules

- `<umi/utils.h>`
- `<umi/usart.h>`
- `<umi/eeprom.h>`
- `<umi/keypad.h>`
- `<umi/lcd.h>`

## Project Structure

```
libumi/
├── src/              # Library source code
├── include/
│   ├── umi.h         # Main header (includes all modules)
│   └── umi/          # Individual module headers
├── examples/         # Example programs
├── docs/             # Documentation
├── obj/              # Build artifacts (generated)
└── lib/              # Compiled library (generated)
```

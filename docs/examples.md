# libumi Examples

This document provides an overview of all example programs included with libumi.

## Table of Contents

- [Overview](#overview)
- [lcd_4b](#lcd_4b)
- [keypad_usart](#keypad_usart)
- [eeprom_usart](#eeprom_usart)

---

## Overview

All examples are located in the `examples/` directory. Each example is self-contained with:

- Source code (`.c` file)
- Makefile
- README

### Common Build Commands

```bash
# Build an example
cd examples/<example_name>
make

# Flash to microcontroller
make flash

# Clean build artifacts
make clean

# View compiled size
make size
```

---

## [lcd_4b](examples/lcd_4b/)

### Description

Demonstrates LCD initialization and display in 4-bit mode operation.

---

## [keypad_usart](examples/keypad_usart/)

### Description

Demonstrates keypad scanning with serial output.

---

## [eeprom_usart](examples/eeprom_usart/)

### Description

Demonstrates EEPROM read/write operations with serial output.

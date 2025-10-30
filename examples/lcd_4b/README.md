# LCD 4-bit Mode Example

Demonstrates LCD initialization and display in 4-bit mode operation.

## Hardware Requirements

- ATmega328P (Arduino UNO)
- 16x2 HD44780-compatible LCD display
- 10kΩ potentiometer (for contrast adjustment)
- Jumper wires
- Breadboard

See [hardware-setup.md](/docs/hardware-setup.md#lcd-display-16x2) for complete hardware setup.

## Building and Flashing

```bash
# Build the example
make

# Flash to your board
make flash

# Clean build artifacts
make clean
```

## Expected Behavior

1. LCD backlight turns on
2. Blinking cursor appears
3. "LCD works!" is displayed on the screen

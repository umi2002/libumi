# Keypad USART Example

Demonstrates keypad scanning with serial output.

## Hardware Requirements

- ATmega328P (Arduino UNO)
- 4x4 matrix keypad
- USB cable (for serial communication)
- Jumper wires

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

1. Open a serial monitor at 9600 baud
2. You'll see: "Keypad USART example started!"
3. Press any key on the keypad
4. The key is transmitted as a byte

## Monitoring Serial Output

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

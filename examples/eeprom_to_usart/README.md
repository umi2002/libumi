# EEPROM to USART Example

Demonstrates EEPROM read operations with serial output.

## Hardware Requirements

- ATmega328P (Arduino UNO)
- USB cable (for serial communication)

**No external components required!**

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

1. Open serial monitor at 9600 baud
2. You should see the entire contents of the EEPROM\*

**\*Note:** You can try the [usart_to_eeprom](/examples/usart_to_eeprom/) example to test the behavior.

## Serial Communication

**Bash:**

```bash
stty -F /dev/ttyACM0 \
  9600 \
  cs8 \
  -cstopb \
  -parenb \
  raw \

// Write
echo "Hello" > /dev/ttyACM0
// Read
cat /dev/ttyACM0 9600
```

**Note:** It is recommended to use a serial monitoring software for ease of use.

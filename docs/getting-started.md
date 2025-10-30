# Getting Started with libumi

This guide will help you set up libumi and get your first program running.

## Prerequisites

Before you begin, ensure you have the following installed:

- **avr-gcc**: AVR C compiler
- **avr-libc**: C library for AVR microcontrollers
- **avrdude**: Tool for flashing programs to AVR chips
- **make**: Build automation tool

### Installing Prerequisites

**On Arch Linux:**

```bash
sudo pacman -S avr-gcc avr-libc avrdude make
```

## Installing libumi

### 1. Clone the Repository

```bash
git clone https://github.com/umi2002/libumi.git
cd libumi
```

### 2. Build the Library

```bash
make
```

This compiles all source files and creates `lib/libumi.a`.

### 3. Install System-Wide (Optional but Recommended)

```bash
sudo make install
```

This installs:

- `libumi.a` to `/usr/local/lib/`
- `umi.h` to `/usr/local/include/`

**Note**: System-wide installation allows you to use the library from any project without specifying paths.

### 4. Uninstalling

If you need to remove the library:

```bash
sudo make uninstall
```

## Hardware Setup

### Connecting Your ATmega328P

1. **Connect your Arduino UNO** or ATmega328P board to your computer via USB
2. **Check the device path**:

   ```bash
   ls /dev/ttyACM*
   ```

   Common path: `/dev/ttyACM0` (Linux)

## Running An Example

**Update the port** if needed in `examples/common.mk`:

```makefile
PORT = /dev/ttyACM0  # Change this to your port
```

### 1. Navigate to an Example

```bash
cd examples/<example_name>
```

### 2. Wire Up the Hardware

See [hardware-setup.md](hardware-setup.md) for wiring setup specific to each example.

### 3. Build the Example

```bash
make
```

This creates:

- `build/<example_name>.elf` - Executable
- `build/<example_name>.hex` - Hex file for flashing

### 4. Flash to Microcontroller

```bash
make flash
```

This uploads the program to your board.

### 5. Clean Build Artifacts

```bash
make clean
```

## Creating Your Own Project

Create `my_project.c`:

```c
#include <avr/io.h>
#include <umi.h>

int main() {
    USARTInit();
    USARTTransmitStr("Hello from libumi!\n");

    while(1) {
        // Main loop
    }

    return 0;
}
```

**Compile:**

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os \
    -I/usr/local/include my_project.c -o my_project.elf \
    -L/usr/local/lib -lumi

avr-objcopy -O ihex -R .eeprom my_project.elf my_project.hex
```

**Flash:**

```bash
avrdude -p atmega328p -c arduino -P /dev/ttyACM0 -b 115200 \
    -U flash:w:my_project.hex:i
```

## Next Steps

- Explore the [API Reference](api-reference.md)
- Read about [Hardware Setup](hardware-setup.md)
- Check out all [Examples](examples.md)
- Start building your own projects!

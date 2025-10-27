# Common Makefile configuration for all libumi examples
# Each example should define TARGET and SRC, then include this file

# Target microcontroller
MCU = atmega328p
F_CPU = 16000000UL

# Programmer settings
PROGRAMMER = arduino
PORT = /dev/ttyACM1
BAUD = 115200

# Toolchain
CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size

# Compiler and linker flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -Werror -I/usr/local/include
LDFLAGS = -mmcu=$(MCU) -L/usr/local/lib -lumi


# Targets
.PHONY: all flash clean size

all: $(TARGET).hex size

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

size: $(TARGET).elf
	@echo "Size of $(TARGET).elf:"
	@$(SIZE) --format=avr --mcu=$(MCU) $<

flash: $(TARGET).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$<:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex

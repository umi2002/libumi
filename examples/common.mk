# Common Makefile configuration for all libumi examples
# Each example should define TARGET and SRC, then include this file

# Target microcontroller
MCU = atmega328p
F_CPU = 16000000UL

# Programmer settings
PROGRAMMER = arduino
PORT = /dev/ttyACM0
BAUD = 115200

# Toolchain
CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size

# Compiler and linker flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -Werror -I/usr/local/include
LDFLAGS = -mmcu=$(MCU) -L/usr/local/lib -lumi

# Build directory
BUILD_DIR = build

# Targets
.PHONY: all flash clean size

all: $(BUILD_DIR)/$(TARGET).hex size

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

size: $(BUILD_DIR)/$(TARGET).elf
	@echo "Size of $(TARGET).elf:"
	@$(SIZE) --format=avr --mcu=$(MCU) $<

flash: $(BUILD_DIR)/$(TARGET).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$<:i

clean:
	rm -rf $(BUILD_DIR)

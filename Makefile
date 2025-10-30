# Target microcontroller
MCU = atmega328p
F_CPU = 16000000UL

# Programmer and port
PROGRAMMER = arduino
PORT = /dev/ttyACM0
BAUD = 115200

# Toolchain commands
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Compiler flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -Iinclude

# System directories
SYS_LIB = /usr/local/lib
SYS_INC = /usr/local/include

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INC_DIR = include

# Library name
LIB_NAME = libumi.a

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Targets
.PHONY: all clean install uninstall

all: $(LIB_DIR)/$(LIB_NAME)

# Create the static library
$(LIB_DIR)/$(LIB_NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

# Install library
install: $(LIB_DIR)/$(LIB_NAME)
	cp $(LIB_DIR)/$(LIB_NAME) $(SYS_LIB)
	cp $(INC_DIR)/umi.h $(SYS_INC)
	mkdir -p $(SYS_INC)/umi
	cp $(INC_DIR)/umi/*.h $(SYS_INC)/umi/

# Uninstall library
uninstall:
	rm -f $(SYS_LIB)/$(LIB_NAME)
	rm -f $(SYS_INC)/umi.h
	rm -rf $(SYS_INC)/umi/

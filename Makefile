CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2
CFLAGS  += -Iinclude

SRC_DIR   = src
BUILD_DIR = build

ifeq ($(OS),Windows_NT)
    TARGET = game.exe
else
    TARGET = game
endif

SOURCES = $(shell find $(SRC_DIR) -name '*.c')
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(OBJECTS:.o=.d)

.PHONY: all clean


SOURCES := main.c calculations.c system.c

BUILD_DIR := build

OBJ := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

SRC_DIR := source
SRC := $(SOURCES:%.c=$(SRC_DIR)/%.c)

CC := gcc
CFLAGS := -O0 -g3 -Wall -Werror

.DEFAULT_GOAL := Regulator_Tuner

Regulator_Tuner : $(OBJ)
	$(CC) $(OBJ) -o $@

$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC)  -c $< -o $@

.Phony : Clean
Clean :
	rm -rf $(.DEFAULT_GOAL) $(BUILD_DIR)


# Improved Makefile for compiling all victim and attack programs.
# It uses pattern rules to avoid repetition and places output in a 'bin' directory.

# --- Configuration ---
CC = gcc
# Base flags for all compilations
CFLAGS = -m32 -fno-stack-protector -no-pie -g
# Specific flags for targets that need an executable stack
CFLAGS_EXEC = $(CFLAGS) -z execstack
# Specific flags for targets that need a non-executable stack
CFLAGS_NOEXEC = $(CFLAGS) -z noexecstack

# --- Directories ---
SRC_DIR_VICTIM = victims
SRC_DIR_ATTACK = attack_templates
CONFIG_DIR = config
# All output binaries will go into the 'bin' directory
BIN_DIR = bin

# --- Source & Target Definitions ---
# List all the victim numbers that use the EXEC stack flag
VICTIM_EXEC_NUMS := 1 2 3 4 5 6 7 8
# List the victim numbers that use the NOEXEC stack flag
VICTIM_NOEXEC_NUMS := 9

# Automatically generate the full target names (e.g., bin/victim1-binary)
VICTIM_TARGETS_EXEC := $(patsubst %,$(BIN_DIR)/victim%-binary,$(VICTIM_EXEC_NUMS))
VICTIM_TARGETS_NOEXEC := $(patsubst %,$(BIN_DIR)/victim%-binary,$(VICTIM_NOEXEC_NUMS))

# Define attack targets
ATTACK_TARGETS := $(BIN_DIR)/attack1-binary $(BIN_DIR)/attack3-binary $(BIN_DIR)/attack4-binary \
                  $(BIN_DIR)/attack5-binary $(BIN_DIR)/attack6-binary $(BIN_DIR)/attack7-binary

# --- Build Rules ---

# The 'all' rule is the default. It now ONLY builds the victim programs.
# Attack templates are not built by default as they require student modification.
all: $(VICTIM_TARGETS_EXEC) $(VICTIM_TARGETS_NOEXEC)

# Before building anything, create the binary directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# --- Pattern Rule for EXEC Stack Victims ---
# This single rule handles victims 1 through 8.
# It says: to make a file like 'bin/victimX-binary', you need 'victims/victimX.c'
$(VICTIM_TARGETS_EXEC): $(BIN_DIR)/victim%-binary: $(SRC_DIR_VICTIM)/victim%.c util-program.c | $(BIN_DIR)
	@echo "Compiling (exec stack): $@"
	$(CC) $(CFLAGS_EXEC) -o $@ $< util-program.c -I./$(CONFIG_DIR)

# --- Pattern Rule for NOEXEC Stack Victims ---
# This single rule handles victim 9.
$(VICTIM_TARGETS_NOEXEC): $(BIN_DIR)/victim%-binary: $(SRC_DIR_VICTIM)/victim%.c util-program.c | $(BIN_DIR)
	@echo "Compiling (no-exec stack): $@"
	$(CC) $(CFLAGS_NOEXEC) -o $@ $< util-program.c -I./$(CONFIG_DIR)

# --- Pattern Rule for Attacks ---
# This rule handles all attack binaries. They can be built individually.
# Example: make bin/attack1-binary
$(ATTACK_TARGETS): $(BIN_DIR)/attack%-binary: $(SRC_DIR_ATTACK)/attack%.c util-program.c | $(BIN_DIR)
	@echo "Compiling (attack): $@"
	$(CC) -m32 -o $@ $< util-program.c -I./$(CONFIG_DIR)

# --- Cleanup Rule ---
# Removes the entire bin directory and other generated files.
clean:
	@echo "Cleaning up..."
	rm -rf $(BIN_DIR) *.o *-payload *.txt

.PHONY: all clean


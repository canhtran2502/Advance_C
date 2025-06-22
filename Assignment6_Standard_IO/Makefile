LOG_NAME = application.log

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinc -g

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/logger.c \
       main.c

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Output executable
TARGET = Logger

# Build rules
all: $(OBJ_DIR) $(STATE_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(STATE_DIR):
	mkdir -p $(STATE_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule for object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(LOG_NAME)
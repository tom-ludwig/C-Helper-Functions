# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g

# Source files
SRCS = dynamic_array.c dynamic_array_example.c

# Header files
HEADERS = dynamic_array.h

# Output binary
TARGET = program

# Object files (automatically derived from source files)
OBJS = $(SRCS:.c=.o)

# Default target (builds the program)
all: $(TARGET)

# Rule to build the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to prevent conflicts with files named 'all' or 'clean'
.PHONY: all clean

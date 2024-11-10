# I had ChatGPT write this Makefile for me 💀

# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Source and object files
SRCS = mincoins.c vec.c
OBJS = $(SRCS:.c=.o)

# Output executable
EXEC = mincoins

# Default target: build the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(EXEC)


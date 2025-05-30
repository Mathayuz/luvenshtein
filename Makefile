TARGET = main
CC = gcc
CFLAGS = -Wall -O2 -std=c99 -I./lua

# Fontes Lua (todos os .c da pasta lua/)
LUA_SRC = $(wildcard lua/*.c)

SRC = main.c levenshtein.c hamming.c
OBJ = $(SRC:.c=.o)

default: $(TARGET)

$(TARGET): $(OBJ) $(LUA_SRC)
	$(CC) $(CFLAGS) -o $@ $^ -lm

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

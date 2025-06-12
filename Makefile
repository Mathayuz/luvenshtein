# Nome do executável
TARGET = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -O2 -std=c99 -I./lua

# Arquivos-fonte
SRC = main.c levenshtein.c hamming.c \
      lua/lapi.c lua/lauxlib.c lua/lbaselib.c lua/lcode.c lua/lcorolib.c lua/lctype.c \
      lua/ldblib.c lua/ldebug.c lua/ldo.c lua/ldump.c lua/lfunc.c lua/lgc.c lua/linit.c \
      lua/liolib.c lua/llex.c lua/lmathlib.c lua/lmem.c lua/loadlib.c lua/lobject.c \
      lua/lopcodes.c lua/loslib.c lua/lparser.c lua/lstate.c lua/lstring.c lua/lstrlib.c \
      lua/ltable.c lua/ltablib.c lua/ltm.c lua/lundump.c lua/lutf8lib.c lua/lvm.c

# Regra principal
default: $(TARGET)

# Como compilar o programa
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar os arquivos gerados
clean:
	rm -f $(TARGET)

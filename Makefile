# Nome do executável final
TARGET = luvenshtein

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -O2 -std=c99

# Bibliotecas do Lua (ajuste conforme a versão do sistema)
LUA_FLAGS = `pkg-config --cflags --libs lua5.4`

# Fontes do projeto
SRC = main.c levenshtein.c
OBJ = $(SRC:.c=.o)

# Regra padrão
default: $(TARGET)

# Compila o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LUA_FLAGS)

# Executa o programa
run: $(TARGET)
	./$(TARGET)

# Limpa arquivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

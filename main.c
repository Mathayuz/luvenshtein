// Lucas de Oliveira Fratus RA:134698
// Matheus Cenerini Jacomini RA:134700

// Como executar?
// make	   # compilar
// make run 	# executar
// make clean	# limpar


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.h"
#include "hamming.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


int c_levenshtein(lua_State *L) {
    const char *s1 = luaL_checkstring(L, 1);
    const char *s2 = luaL_checkstring(L, 2);
    int dist = levenshtein(s1, s2);
    lua_pushinteger(L, dist); // colocamos "dist" no topo da stack
    return 1;  
}

int c_hamming(lua_State *L) {
    // checa se o primeiro e segundo argumento são strings e retorna o valor
    const char *s1 = luaL_checkstring(L, 1);
    const char *s2 = luaL_checkstring(L, 2);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 != len2) {
    return luaL_error(L,
        "Hamming exige strings com o mesmo comprimento (%zu vs %zu).", len1, len2);
    }
    int dist = hamming(s1, s2, len1);
    lua_pushinteger(L, dist); // colocamos "dist" no topo da stack
    return 1;
}

int main(void) {
    lua_State *L = luaL_newstate();  // ponteiro para a maquina virtual do Lua (permite compartilha data entre LUA e C)
    if (!L) {
        fprintf(stderr, "Erro ao criar estado Lua.\n");
        return EXIT_FAILURE;
    }

    luaL_openlibs(L); // permite a chamada de bibliotecas dentro do código lua. (não é obrigatorio dependendo do caso)

    // registra uma função C como uma função global disponivel no amb. Lua.
    // equaivale a lua_pushcfunction() seguido de lua_setglobal()
    lua_register(L, "levenshtein", c_levenshtein);
    lua_register(L, "hamming", c_hamming);


    // roda o script lua
    if (luaL_dofile(L, "script.lua")) {
        fprintf(stderr, "Erro ao executar script.lua: %s\n", lua_tostring(L, -1));
        lua_close(L);
        return EXIT_FAILURE;
    }

    lua_close(L);
    return EXIT_SUCCESS;
}


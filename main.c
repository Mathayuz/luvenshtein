#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.h"
#include "hamming.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// Função wrapper que será registrada no Lua
int c_levenshtein(lua_State *L) {
    const char *s1 = luaL_checkstring(L, 1);
    const char *s2 = luaL_checkstring(L, 2);
    int dist = levenshtein(s1, s2);
    lua_pushinteger(L, dist);
    return 1;  // número de valores de retorno
}

int c_hamming(lua_State *L) {
    const char *s1 = luaL_checkstring(L, 1);
    const char *s2 = luaL_checkstring(L, 2);
    int dist = hamming(s1, s2);
    lua_pushinteger(L, dist);
    return 1;
}

int main(void) {
    lua_State *L = luaL_newstate();
    if (!L) {
        fprintf(stderr, "Erro ao criar estado Lua.\n");
        return EXIT_FAILURE;
    }

    luaL_openlibs(L);

    lua_register(L, "levenshtein", c_levenshtein);
    lua_register(L, "hamming", c_hamming);

    if (luaL_dofile(L, "script.lua")) {
        fprintf(stderr, "Erro ao executar script.lua: %s\n", lua_tostring(L, -1));
        lua_close(L);
        return EXIT_FAILURE;
    }

    lua_close(L);
    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levenshtein.h"

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

int main(void) {
    lua_State *L = luaL_newstate(); // cria nova VM
    if (!L) {
        fprintf(stderr, "Erro ao criar estado Lua.\n");
        return EXIT_FAILURE;
    }

    luaL_openlibs(L); // abre bibliotecas padrão do Lua

    // Registra a função C como "levenshtein" em Lua
    lua_register(L, "levenshtein", c_levenshtein);

    // Executa o script Lua
    if (luaL_dofile(L, "script.lua")) {
        fprintf(stderr, "Erro ao executar script.lua: %s\n", lua_tostring(L, -1));
        lua_close(L);
        return EXIT_FAILURE;
    }

    lua_close(L); // encerra a VM
    return EXIT_SUCCESS;
}

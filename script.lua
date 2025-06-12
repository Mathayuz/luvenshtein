--[[] 
  Esse script em Lua chama as funções definidas em C e exibe no console as distâncias 
  de Levenshtein e de Hamming para algumas duplas de strings
]]--
print("Distância de Levenshtein entre pares de strings:")
local pares_lev = {
    { "casa",     "caso" },
    { "kitten",   "sitting" },
    { "flor",     "flora" },
    { "intenção", "atenção" },
    { "matheus", "mateus" }
}

for i, par in ipairs(pares_lev) do
    local s1, s2 = par[1], par[2]
    local dist = levenshtein(s1, s2)
    print(string.format("\"%s\" - \"%s\": %d", s1, s2, dist))
end

print("\nDistância de Hamming entre pares de strings (mesmo comprimento):")
local pares_ham = {
    { "1011101", "1001001" },
    { "carolina", "caroline" },
    { "lucas", "vitor" },
    { "1011101", "1011111" },
    { "lucas", "lukas" },
    { "oi", "hi"}
}
for _, par in ipairs(pares_ham) do
    local s1, s2 = par[1], par[2]
    local dist = hamming(s1, s2)
    print(string.format("\"%s\" - \"%s\": %d", s1, s2, dist))
end

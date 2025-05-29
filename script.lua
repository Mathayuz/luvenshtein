print("Calculando distância de Levenshtein entre pares de strings:")

local pares = {
    { "casa", "caso" },
    { "kitten", "sitting" },
    { "flor", "flora" },
    { "intenção", "atenção" }
}

for _, par in ipairs(pares) do
    local s1, s2 = par[1], par[2]
    local dist = levenshtein(s1, s2)
    print(string.format("Distância entre \"%s\" e \"%s\": %d", s1, s2, dist))
end

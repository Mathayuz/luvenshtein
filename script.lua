-- Lucas de Oliveira Fratus  RA: 134698
-- Matheus Cenerini Jacomini RA: 134700
--
-- Como executar?
-- make    # compilar
-- make run  # executar
-- make clean  # limpar



-- Script em Lua para que chama as funções de c quem calculam as distâncias de Levenshtein e Hamming
-- dos pares de strings
--
-- Listas paralelas de pares para Levenshtein
local lev_s1 = { "casa", "kitten", "flor", "intenção", "matheus", "pihs" }
local lev_s2 = { "caso", "sitting","flora", "atenção", "mateus", "pihs" }

print("Distância de Levenshtein entre pares de strings:")
for i = 1, #lev_s1 do
  local d = levenshtein(lev_s1[i], lev_s2[i])
  print(lev_s1[i] .. " - " .. lev_s2[i] .. ": " .. d)
end

-- Listas paralelas de pares para Hamming
local ham_s1 = { "1011101", "carolina", "lucas", "1011101", "lucas", "oi", "pihs" }
local ham_s2 = { "1001001", "caroline", "vitor", "1011111", "lukas", "hi", "pihs" }

print("\nDistância de Hamming entre pares de strings (mesmo comprimento):")
for i = 1, #ham_s1 do
  local d = hamming(ham_s1[i], ham_s2[i])
  print(ham_s1[i] .. " - " .. ham_s2[i] .. ": " .. d)
end

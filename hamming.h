#ifndef HAMMING_H
#define HAMMING_H

#include <stddef.h>

// Calcula a distância de Hamming entre duas strings de mesmo tamanho.
// Parâmetros:
//   s1, s2: strings a comparar
//   len: tamanho das strings
// Retorna:
//   distância de Hamming (número de posições diferentes) ou -1 se entrada inválida.
int hamming(const char *s1, const char *s2, size_t len);

#endif /* HAMMING_H */


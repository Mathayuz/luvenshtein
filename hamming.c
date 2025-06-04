#include "hamming.h"

int hamming(const char *s1, const char *s2, size_t len) {
    if (!s1 || !s2 || len == 0) {
        return -1; // entrada inválida
    }

    int dist = 0;
    for (size_t i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            dist++;
        }
    }

    return dist;
}


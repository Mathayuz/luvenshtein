# Luvenshtein

Projeto de integração entre C e Lua para cálculo da distância de Levenshtein entre strings, com o interpretador Lua embutido.

Este projeto foi desenvolvido como parte das atividades da disciplina **Programação para Interfaceamento de Hardware e Software** na Universidade Estadual de Maringá.

---

## 📌 Objetivo

Demonstrar a integração entre:
- Um programa principal escrito em **C**,
- Uma biblioteca externa, também em **C**, que implementa o algoritmo de **Levenshtein**,
- E um script em **Lua** embutido no programa, que interage com a biblioteca e exibe resultados.

---

## ▶️ Como compilar e executar

### Pré-requisitos
- Compilador GCC

### Comandos

```bash
make        # Compila o projeto, incluindo o interpretador Lua embutido
make run    # Executa o programa principal
make clean  # Remove arquivos compilados

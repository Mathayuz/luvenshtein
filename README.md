# Luvenshtein

Projeto de integração entre C e Lua para cálculo da distância de Levenshtein entre strings.

Este projeto foi desenvolvido como parte das atividades da disciplina **Programação para Interfaceamento de Hardware e Software** na Universidade Estadual de Maringá.

---

## 📌 Objetivo

Demonstrar a integração entre:
- Um programa principal escrito em **C**,
- Uma biblioteca externa, também em **C**, que implementa o algoritmo de **Levenshtein**,
- E um script em **Lua** embutido no programa, que interage com a biblioteca e exibe resultados.

---

## 🔧 Estrutura do Projeto


- `main.c`: programa principal que embute o interpretador Lua e expõe a função de distância de Levenshtein.
- `levenshtein.c/h`: implementação da função de distância de Levenshtein.
- `script.lua`: script que chama a função em C e imprime as distâncias de pelo menos quatro pares de strings.
- `Makefile`: automatiza a compilação, execução e limpeza do projeto.
- `LICENSE`: define a licença de uso do código-fonte.
- `README.md`: este arquivo.

---

## ▶️ Como executar

### Pré-requisitos
- GCC (compilador C)
- Lua 5.x instalado no sistema (incluindo headers `lua.h`, `lauxlib.h`, etc.)

### Comandos

```bash
make        # Compila o projeto
make run    # Executa o projeto
make clean  # Remove os arquivos compilados

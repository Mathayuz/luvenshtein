# Luvenshtein (Integração Lua + Levenshtein.c + Hamming.c)

Este projeto demonstra a integração de código em C com um script em Lua, incorporando dois algoritmos para comparação de strings:

- Distância de Levenshtein: número mínimo de operações (inserção, remoção ou substituição) necessárias para transformar uma string em outra.

- Distância de Hamming: número de posições em que duas strings de mesmo comprimento diferem.

Este projeto foi desenvolvido como parte  da disciplina **Programação para Interfaceamento de Hardware e Software** na Universidade Estadual de Maringá.

## Objetivo

Demonstrar a integração entre:
- Um programa principal escrito em **C**,
- Uma biblioteca externa, também em **C**, que implementa o algoritmo de **Levenshtein**,
- Uma biblioteca externa, também em **C**, que implementa o algoritmo de **Hamming**,
- E um script em **Lua** embutido no programa, que interage com a biblioteca e exibe resultados.


## Pré-requisitos
- Compilador GCC
- GNU Make
- Lua incluido no repositório (sem a necessidade de instalação)

## Como compilar
No diretório raiz do projeto, execute o seguinte comando:
```bash
make        # Compila o projeto, incluindo o interpretador Lua embutido
```

## Como executar
Para executar o script Lua e exibir as distâncias no terminal, execute:
```bash
make run    # Executa o programa principal
```
Para limpar (remover) os arquivos compilados:
```bash
make clean 
```

## Autores
Lucas de Oliveira Fratus
Matheus Cenerini Jacomini

## Licença

Este projeto e as implementações de Levenshtein e Hamming estão licenciadas sob a MIT License.

Veja o diretório LICENSES para as licenças completas.

## Autores
- Lucas de Oliveira Fratus
- Matheus Cenerini Jacomini

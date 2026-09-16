# Atividade - Controle de Poltronas do Cinema

Atividade desenvolvida na disciplina de **Algoritmo e Pensamento Computacional**, utilizando a linguagem C.

## Objetivo

Criar um programa para representar a situação das poltronas de uma sala de cinema organizada em 3 fileiras e 3 colunas.

Cada posição da matriz representa uma poltrona:

- `0` = poltrona livre;
- `1` = poltrona ocupada.

## Requisitos da atividade

O programa deve:

- Declarar uma matriz 3x3 de números inteiros;
- Ler os valores informados pelo usuário;
- Utilizar `0` para representar poltronas livres;
- Utilizar `1` para representar poltronas ocupadas;
- Exibir a situação da sala;
- Informar a quantidade de poltronas livres;
- Informar a quantidade de poltronas ocupadas.

## Conceitos utilizados

- Matrizes bidimensionais;
- Laços `for` aninhados;
- Estruturas condicionais `if` e `else if`;
- Contadores;
- Entrada de dados com `scanf`;
- Saída de dados com `printf`.

## Representação da sala

A sala possui 3 fileiras e 3 colunas:

```text
mat[0][0]  mat[0][1]  mat[0][2]
mat[1][0]  mat[1][1]  mat[1][2]
mat[2][0]  mat[2][1]  mat[2][2]

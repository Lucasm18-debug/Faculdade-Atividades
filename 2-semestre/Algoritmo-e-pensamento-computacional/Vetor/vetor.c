#include <stdio.h> //Biblioteca padrão de entrada e saída

int main() { //Função principal do programa

    int numeros[20]; //Declara um vetor chamado numeros
    int i; //Declara a variável

    int somaMultiplos = 0; //Guarda a soma dos valores que forem múltiplos de 3
    int somaPares = 0; //Guarda a soma dos valores pares

    int quantidadePares = 0; //Conta quantos números pares existem
    int quantidadeNegativos = 0; //Conta quantos números negativos existem

    //Declarando as variáveis que serão armazenadas
    int maior; //Maior número encontrado
    int menor; //Menor número encontrado
    for (i = 0; i < 20; i++) { //For percorrer o vetor inteiro

        printf("Digite o %d numero: ", i + 1); //Mostra qual número o usuário deve digitar
        scanf("%d", &numeros[i]); //Programa lê um número inteiro e guarda na posição atual do vetor

        if (numeros[i] % 3 == 0) { //Verificando se o número é múltiplo de 3
            somaMultiplos = somaMultiplos + numeros[i]; //Se for múltiplo de 3, será adicionado ao acumulador
        }

        if (numeros[i] % 2 == 0) { //Verificando se o número é par
            somaPares = somaPares + numeros[i]; //Adicionando o número par a soma dos pares
            quantidadePares++; //Aumentar o contador de pares
        }

        if (numeros[i] < 0) { //Verificando se o número é negativo
            quantidadeNegativos++; //Aumentar o contador de negativos
        }

        if (i == 0) { //Primeira posição
            maior = numeros[i];
            menor = numeros[i];
        } else { //Se não é o primeiro número faça comparações

            if (numeros[i] > maior) { //É maior que o maior número encontrado?
                maior = numeros[i]; //Atualizamos o maior valor
            }

            if (numeros[i] < menor) { //É menor que o menor número encontrado?
                menor = numeros[i]; //Atualizamos o menor valor
            }
        }
    }

    printf("\nSoma dos multiplos de 3: %d\n", somaMultiplos);

    if (quantidadePares > 0) {
        float mediaPares = (float)somaPares / quantidadePares;
        printf("Media dos elementos pares: %.2f\n", mediaPares);
    } else {
        printf("Nao existem elementos pares.\n");
    }

    printf("Quantidade de numeros negativos: %d\n", quantidadeNegativos);
    printf("Quantidade de numeros pares: %d\n", quantidadePares);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    printf("\nElementos do vetor:\n");

    for (i = 0; i < 20; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}

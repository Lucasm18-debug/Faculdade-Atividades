#include <stdio.h>
#include <string.h>
#include "senhas.h"

// Salva os registros no arquivo
void salvarArquivo(Senha senhas[], int quantidade) {
    FILE *arquivo = fopen("senhas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar os dados!\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s\n", senhas[i].servico);
        fprintf(arquivo, "%s\n", senhas[i].usuario);
        fprintf(arquivo, "%s\n", senhas[i].senha);
    }

    fclose(arquivo);
}

// Carrega os registros do arquivo
void carregarArquivo(Senha senhas[], int *quantidade) {
    FILE *arquivo = fopen("senhas.txt", "r");

    if (arquivo == NULL) {
        return;
    }

    while (*quantidade < MAX_SENHAS) {
        char servico[TAMANHO];
        char usuario[TAMANHO];
        char senha[TAMANHO];

        if (fgets(servico, TAMANHO, arquivo) == NULL)
            break;

        if (fgets(usuario, TAMANHO, arquivo) == NULL)
            break;

        if (fgets(senha, TAMANHO, arquivo) == NULL)
            break;

        servico[strcspn(servico, "\n")] = '\0';
        usuario[strcspn(usuario, "\n")] = '\0';
        senha[strcspn(senha, "\n")] = '\0';

        strcpy(senhas[*quantidade].servico, servico);
        strcpy(senhas[*quantidade].usuario, usuario);
        strcpy(senhas[*quantidade].senha, senha);

        (*quantidade)++;
    }

    fclose(arquivo);
}

#include <stdio.h>
#include <string.h>
#include "senhas.h"

// Funcao para ler textos
void lerTexto(char texto[], int tamanho, const char mensagem[]) {
    do {
        printf("%s", mensagem);

        if (fgets(texto, tamanho, stdin) == NULL) {
            texto[0] = '\0';
            return;
        }

        size_t fim = strcspn(texto, "\n");

        if (texto[fim] == '\n') {
            texto[fim] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if (strlen(texto) == 0) {
            printf("Campo obrigatorio!\n");
        }

    } while (strlen(texto) == 0);
}

// Procura um servico cadastrado
int buscarSenha(Senha senhas[], int quantidade, const char servico[]) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(senhas[i].servico, servico) == 0) {
            return i;
        }
    }

    return -1;
}

// Cadastra uma nova senha
void cadastrarSenha(Senha senhas[], int *quantidade) {
    if (*quantidade >= MAX_SENHAS) {
        printf("Limite de cadastros atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR SENHA ---\n");

    lerTexto(senhas[*quantidade].servico, TAMANHO,
             "Nome do servico: ");

    lerTexto(senhas[*quantidade].usuario, TAMANHO,
             "Nome de usuario: ");

    lerTexto(senhas[*quantidade].senha, TAMANHO,
             "Senha: ");

    (*quantidade)++;

    salvarArquivo(senhas, *quantidade);

    printf("\nCadastro realizado com sucesso!\n");
}

// Lista os cadastros
void listarSenhas(Senha senhas[], int quantidade) {
    printf("\n--- LISTA DE SENHAS ---\n");

    if (quantidade == 0) {
        printf("Nenhuma senha cadastrada.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nCadastro %d\n", i + 1);
        printf("Servico: %s\n", senhas[i].servico);
        printf("Usuario: %s\n", senhas[i].usuario);
        printf("Senha: %s\n", senhas[i].senha);
    }
}

// Pesquisa uma senha
void pesquisarSenha(Senha senhas[], int quantidade) {
    char servico[TAMANHO];

    printf("\n--- PESQUISAR SENHA ---\n");

    lerTexto(servico, TAMANHO, "Digite o servico: ");

    int posicao = buscarSenha(senhas, quantidade, servico);

    if (posicao == -1) {
        printf("Servico nao encontrado!\n");
    } else {
        printf("\nServico: %s\n", senhas[posicao].servico);
        printf("Usuario: %s\n", senhas[posicao].usuario);
        printf("Senha: %s\n", senhas[posicao].senha);
    }
}

// Edita um cadastro
void editarSenha(Senha senhas[], int quantidade) {
    char servico[TAMANHO];

    printf("\n--- EDITAR SENHA ---\n");

    lerTexto(servico, TAMANHO, "Servico que deseja editar: ");

    int posicao = buscarSenha(senhas, quantidade, servico);

    if (posicao == -1) {
        printf("Servico nao encontrado!\n");
        return;
    }

    lerTexto(senhas[posicao].usuario, TAMANHO,
             "Novo usuario: ");

    lerTexto(senhas[posicao].senha, TAMANHO,
             "Nova senha: ");

    salvarArquivo(senhas, quantidade);

    printf("Cadastro atualizado com sucesso!\n");
}

// Exclui um cadastro
void excluirSenha(Senha senhas[], int *quantidade) {
    char servico[TAMANHO];
    char confirmacao[TAMANHO];

    printf("\n--- EXCLUIR SENHA ---\n");

    lerTexto(servico, TAMANHO, "Servico que deseja excluir: ");

    int posicao = buscarSenha(senhas, *quantidade, servico);

    if (posicao == -1) {
        printf("Servico nao encontrado!\n");
        return;
    }

    lerTexto(confirmacao, TAMANHO,
             "Confirma a exclusao? (s/n): ");

    if (confirmacao[0] != 's' && confirmacao[0] != 'S') {
        printf("Exclusao cancelada.\n");
        return;
    }

    for (int i = posicao; i < *quantidade - 1; i++) {
        senhas[i] = senhas[i + 1];
    }

    (*quantidade)--;

    salvarArquivo(senhas, *quantidade);

    printf("Senha excluida com sucesso!\n");
}

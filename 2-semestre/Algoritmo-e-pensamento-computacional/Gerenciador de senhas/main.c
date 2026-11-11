#include <stdio.h>
#include <stdlib.h>
#include "senhas.h"

int main() {
    Senha senhas[MAX_SENHAS];
    int quantidade = 0;
    int opcao;

    carregarArquivo(senhas, &quantidade);

    do {
        printf("\n================================\n");
        printf("       TIA KARLA SOLUCOES\n");
        printf("       GERENCIADOR DE SENHAS\n");
        printf("================================\n");

        printf("1 - Cadastrar nova senha\n");
        printf("2 - Listar senhas\n");
        printf("3 - Pesquisar senha\n");
        printf("4 - Editar senha\n");
        printf("5 - Excluir senha\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");

        char entrada[20];
        char *fim;

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        opcao = (int)strtol(entrada, &fim, 10);

        if (fim == entrada ||
            (*fim != '\n' && *fim != '\0')) {
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                cadastrarSenha(senhas, &quantidade);
                break;

            case 2:
                listarSenhas(senhas, quantidade);
                break;

            case 3:
                pesquisarSenha(senhas, quantidade);
                break;

            case 4:
                editarSenha(senhas, quantidade);
                break;

            case 5:
                excluirSenha(senhas, &quantidade);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

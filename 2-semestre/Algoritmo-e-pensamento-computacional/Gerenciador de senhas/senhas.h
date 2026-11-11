#ifndef SENHAS_H
#define SENHAS_H

#define MAX_SENHAS 100
#define TAMANHO 100

typedef struct {
    char servico[TAMANHO];
    char usuario[TAMANHO];
    char senha[TAMANHO];
} Senha;

// Funcoes de cadastro e gerenciamento
void lerTexto(char texto[], int tamanho, const char mensagem[]);

int buscarSenha(Senha senhas[], int quantidade, const char servico[]);

void cadastrarSenha(Senha senhas[], int *quantidade);

void listarSenhas(Senha senhas[], int quantidade);

void pesquisarSenha(Senha senhas[], int quantidade);

void editarSenha(Senha senhas[], int quantidade);

void excluirSenha(Senha senhas[], int *quantidade);

// Funcoes de armazenamento
void salvarArquivo(Senha senhas[], int quantidade);

void carregarArquivo(Senha senhas[], int *quantidade);

#endif

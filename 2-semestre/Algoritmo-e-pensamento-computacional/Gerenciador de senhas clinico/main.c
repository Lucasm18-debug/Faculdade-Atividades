#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACIENTES 300
#define TAM_CATEGORIA 20

typedef struct {
    char categoria;       /* U = urgente, P = preferencial, N = normal */
    int numero;
    int idade;
    int genero;           /* 1 = feminino, 2 = masculino, 3 = outro */
    int gestante;
    int lactante;
    int necessidadeEspecial;
    int obesidade;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int inicio;
    int fim;
    int quantidade;
} Fila;

typedef struct {
    Fila normal;
    Fila preferencial;
    Fila urgente;
    int proximaNormal;
    int proximaPreferencial;
    int proximaUrgente;
    Paciente emAtendimento;
    int existeAtendimento;
} Sistema;

/* Le um numero inteiro e verifica se esta dentro do intervalo informado. */
int lerInteiro(const char *mensagem, int minimo, int maximo) {
    char entrada[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("Erro na leitura. Tente novamente.\n");
            clearerr(stdin);
            continue;
        }

        valor = strtol(entrada, &fim, 10);
        while (*fim == ' ' || *fim == '\t' || *fim == '\n' || *fim == '\r') {
            fim++;
        }

        if (fim == entrada || *fim != '\0' || valor < minimo || valor > maximo) {
            printf("Opcao invalida. Digite um valor entre %d e %d.\n", minimo, maximo);
        } else {
            return (int)valor;
        }
    }
}

/* Le uma resposta de sim ou nao. */
int lerSimNao(const char *mensagem) {
    printf("%s\n", mensagem);
    return lerInteiro("Digite 1 para Sim ou 0 para Nao: ", 0, 1);
}

/* Inicia uma fila vazia. */
void iniciarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int filaVazia(const Fila *fila) {
    return fila->quantidade == 0;
}

/* Insere um paciente no final da fila. */
int inserirFila(Fila *fila, Paciente paciente) {
    if (fila->quantidade == MAX_PACIENTES) {
        return 0;
    }

    fila->pacientes[fila->fim] = paciente;
    fila->fim = (fila->fim + 1) % MAX_PACIENTES;
    fila->quantidade++;
    return 1;
}

/* Retira o primeiro paciente da fila. */
int retirarFila(Fila *fila, Paciente *paciente) {
    if (filaVazia(fila)) {
        return 0;
    }

    *paciente = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_PACIENTES;
    fila->quantidade--;
    return 1;
}

/* Consulta o primeiro paciente sem retira-lo da fila. */
int consultarFila(const Fila *fila, Paciente *paciente) {
    if (filaVazia(fila)) {
        return 0;
    }

    *paciente = fila->pacientes[fila->inicio];
    return 1;
}

/* Define a categoria de acordo com as regras da atividade. */
char classificarPaciente(const Paciente *paciente) {
    if (paciente->idade > 80) {
        return 'U';
    }

    if (paciente->gestante || paciente->lactante ||
        paciente->necessidadeEspecial || paciente->obesidade) {
        return 'P';
    }

    if ((paciente->genero == 1 && paciente->idade >= 60) ||
        (paciente->genero == 2 && paciente->idade >= 65)) {
        return 'P';
    }

    return 'N';
}

/* Gera a senha com numeracao independente por categoria. */
void gerarSenha(Sistema *sistema, Paciente *paciente) {
    if (paciente->categoria == 'U') {
        sistema->proximaUrgente++;
        paciente->numero = sistema->proximaUrgente;
    } else if (paciente->categoria == 'P') {
        sistema->proximaPreferencial++;
        paciente->numero = sistema->proximaPreferencial;
    } else {
        sistema->proximaNormal++;
        paciente->numero = sistema->proximaNormal;
    }
}

/* Retorna a fila correspondente a categoria. */
Fila *obterFila(Sistema *sistema, char categoria) {
    if (categoria == 'U') {
        return &sistema->urgente;
    }
    if (categoria == 'P') {
        return &sistema->preferencial;
    }
    return &sistema->normal;
}

/* Retorna a proxima fila seguindo a prioridade: urgente, preferencial e normal. */
Fila *proximaFila(Sistema *sistema) {
    if (!filaVazia(&sistema->urgente)) {
        return &sistema->urgente;
    }
    if (!filaVazia(&sistema->preferencial)) {
        return &sistema->preferencial;
    }
    if (!filaVazia(&sistema->normal)) {
        return &sistema->normal;
    }
    return NULL;
}

const char *nomeCategoria(char categoria) {
    if (categoria == 'U') return "Urgente";
    if (categoria == 'P') return "Preferencial";
    return "Normal";
}

void mostrarSenha(const Paciente *paciente) {
    printf("%c%03d - %s\n", paciente->categoria, paciente->numero,
           nomeCategoria(paciente->categoria));
}

/* Cadastra os dados e coloca o paciente na fila correta. */
void cadastrarPaciente(Sistema *sistema) {
    Paciente paciente;
    Fila *fila;

    printf("\n--- Cadastro de paciente ---\n");
    paciente.genero = lerInteiro(
        "Genero (1 - Feminino, 2 - Masculino, 3 - Outro): ", 1, 3);
    paciente.idade = lerInteiro("Idade: ", 0, 120);

    paciente.gestante = 0;
    paciente.lactante = 0;
    if (paciente.genero == 1) {
        paciente.gestante = lerSimNao("A paciente esta gestante?");
        paciente.lactante = lerSimNao("A paciente e lactante?");
    }

    paciente.necessidadeEspecial = lerSimNao("Possui necessidade especial?");
    paciente.obesidade = lerSimNao("Possui condicao de obesidade?");

    paciente.categoria = classificarPaciente(&paciente);
    fila = obterFila(sistema, paciente.categoria);

    if (fila->quantidade == MAX_PACIENTES) {
        printf("Fila cheia. Nao foi possivel cadastrar o paciente.\n");
        return;
    }

    gerarSenha(sistema, &paciente);
    inserirFila(fila, paciente);
    printf("Senha gerada: ");
    mostrarSenha(&paciente);
}

/* Mostra qual senha sera chamada, sem alterar a fila. */
void consultarProximaSenha(Sistema *sistema) {
    Fila *fila = proximaFila(sistema);
    Paciente paciente;

    printf("\n--- Proxima senha ---\n");
    if (fila == NULL || !consultarFila(fila, &paciente)) {
        printf("Nao ha pacientes aguardando.\n");
        return;
    }
    mostrarSenha(&paciente);
}

/* Chama o proximo paciente e registra quem esta em atendimento. */
void chamarProximoPaciente(Sistema *sistema) {
    Fila *fila;

    if (sistema->existeAtendimento) {
        printf("Finalize o atendimento atual antes de chamar outra senha.\n");
        return;
    }

    fila = proximaFila(sistema);
    if (fila == NULL || !retirarFila(fila, &sistema->emAtendimento)) {
        printf("Nao ha pacientes aguardando.\n");
        return;
    }

    sistema->existeAtendimento = 1;
    printf("Senha chamada: ");
    mostrarSenha(&sistema->emAtendimento);
}

/* Identifica a senha que esta sendo atendida. */
void mostrarAtendimentoAtual(const Sistema *sistema) {
    printf("\n--- Atendimento atual ---\n");
    if (!sistema->existeAtendimento) {
        printf("Nenhum paciente em atendimento.\n");
        return;
    }
    mostrarSenha(&sistema->emAtendimento);
}

/* Finaliza o atendimento atual. A senha nao volta para a fila. */
void finalizarAtendimento(Sistema *sistema) {
    if (!sistema->existeAtendimento) {
        printf("Nao existe atendimento em andamento.\n");
        return;
    }

    printf("Atendimento finalizado: ");
    mostrarSenha(&sistema->emAtendimento);
    sistema->existeAtendimento = 0;
}

/* Lista as senhas de uma fila sem modificar sua ordem. */
void listarFila(const Fila *fila) {
    int i;
    int indice;

    if (filaVazia(fila)) {
        printf("Nenhuma\n");
        return;
    }

    for (i = 0; i < fila->quantidade; i++) {
        indice = (fila->inicio + i) % MAX_PACIENTES;
        printf("%c%03d", fila->pacientes[indice].categoria,
               fila->pacientes[indice].numero);
        if (i < fila->quantidade - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/* Exibe a senha atual, as proximas senhas e a quantidade por categoria. */
void mostrarPainel(const Sistema *sistema) {
    printf("\n========== PAINEL DE CHAMADA ==========\n");

    printf("Senha atualmente chamada: ");
    if (sistema->existeAtendimento) {
        mostrarSenha(&sistema->emAtendimento);
    } else {
        printf("Nenhuma\n");
    }

    printf("\nProximas senhas aguardando (por prioridade):\n");
    printf("Urgentes: ");
    listarFila(&sistema->urgente);
    printf("Preferenciais: ");
    listarFila(&sistema->preferencial);
    printf("Normais: ");
    listarFila(&sistema->normal);

    printf("\nQuantidade em espera:\n");
    printf("Urgentes: %d\n", sistema->urgente.quantidade);
    printf("Preferenciais: %d\n", sistema->preferencial.quantidade);
    printf("Normais: %d\n", sistema->normal.quantidade);
    printf("=======================================\n");
}

void inicializarSistema(Sistema *sistema) {
    iniciarFila(&sistema->normal);
    iniciarFila(&sistema->preferencial);
    iniciarFila(&sistema->urgente);
    sistema->proximaNormal = 0;
    sistema->proximaPreferencial = 0;
    sistema->proximaUrgente = 0;
    sistema->existeAtendimento = 0;
}

void mostrarMenu(void) {
    printf("\n===== SISTEMA DE SENHAS DA CLINICA =====\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Consultar proxima senha\n");
    printf("3 - Chamar proximo paciente\n");
    printf("4 - Identificar atendimento atual\n");
    printf("5 - Finalizar atendimento\n");
    printf("6 - Mostrar painel\n");
    printf("0 - Sair\n");
}

int main(void) {
    Sistema sistema;
    int opcao;

    inicializarSistema(&sistema);

    do {
        mostrarMenu();
        opcao = lerInteiro("Escolha uma opcao: ", 0, 6);

        switch (opcao) {
            case 1:
                cadastrarPaciente(&sistema);
                break;
            case 2:
                consultarProximaSenha(&sistema);
                break;
            case 3:
                chamarProximoPaciente(&sistema);
                break;
            case 4:
                mostrarAtendimentoAtual(&sistema);
                break;
            case 5:
                finalizarAtendimento(&sistema);
                break;
            case 6:
                mostrarPainel(&sistema);
                break;
            case 0:
                printf("Sistema encerrado.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

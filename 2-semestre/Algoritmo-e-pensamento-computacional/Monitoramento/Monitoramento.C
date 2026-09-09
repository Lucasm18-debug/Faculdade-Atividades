#include <stdio.h>

int main(void) {
    float limite;
    float temperatura;
    float soma = 0.0f;
    float maior = 0.0f;
    float menor = 0.0f;
    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int primeiraLeitura = 1;
    int continuar = 1;

    /*
     * Valida o limite de temperatura.
     * O programa aceita valores entre -100 e 200 graus Celsius.
     */
    do {
        printf("Digite o limite de temperatura (entre -100 e 200 °C): ");
        if (scanf("%f", &limite) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            limite = -101;
            continue;
        }

        if (limite < -100 || limite > 200) {
            printf("Valor invalido. Digite um limite entre -100 e 200 °C.\n");
        }
    } while (limite < -100 || limite > 200);

    printf("\nMonitoramento iniciado.\n");
    printf("O programa sera encerrado automaticamente apos 3 temperaturas consecutivas acima do limite.\n\n");

    /*
     * Continua lendo temperaturas enquanto o contador de consecutivas
     * permanecer menor que 3.
     */
    while (consecutivas < 3) {
        printf("Digite a temperatura (entre -100 e 200 °C): ");
        if (scanf("%f", &temperatura) != 1) {
            if (feof(stdin)) {
                printf("\nEntrada encerrada.\n");
                continuar = 0;
                break;
            }

            printf("Entrada invalida. Digite um numero.\n\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }

        /* Trata uma leitura fora da faixa permitida. */
        if (temperatura < -100 || temperatura > 200) {
            printf("Temperatura invalida. Digite um valor entre -100 e 200 °C.\n\n");
            continue;
        }

        /* Atualiza quantidade, soma, maior e menor temperatura. */
        quantidade++;
        soma += temperatura;

        if (primeiraLeitura) {
            maior = temperatura;
            menor = temperatura;
            primeiraLeitura = 0;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }

            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        /* Verifica se a temperatura ficou acima do limite. */
        if (temperatura > limite) {
            acimaLimite++;
            consecutivas++;
            printf("Alerta: temperatura acima do limite! (%d consecutiva(s))\n\n", consecutivas);
        } else {
            /* Uma temperatura dentro do limite quebra a sequencia. */
            consecutivas = 0;
            printf("Temperatura dentro do limite. Contador de consecutivas reiniciado.\n\n");
        }
    }

    /* Relatorio final. */
    printf("\n========================================\n");
    printf("       MONITORAMENTO ENCERRADO\n");
    printf("========================================\n");
    printf("Quantidade de temperaturas validas: %d\n", quantidade);
    printf("Maior temperatura: %.2f °C\n", maior);
    printf("Menor temperatura: %.2f °C\n", menor);
    printf("Media das temperaturas: %.2f °C\n", soma / quantidade);
    printf("Temperaturas acima do limite: %d\n", acimaLimite);
    printf("Percentual acima do limite: %.2f%%\n", (acimaLimite * 100.0f) / quantidade);
    if (continuar) {
        printf("Motivo do encerramento: 3 temperaturas consecutivas acima do limite.\n");
    } else {
        printf("Motivo do encerramento: entrada encerrada pelo usuario.\n");
    }

    return 0;
}

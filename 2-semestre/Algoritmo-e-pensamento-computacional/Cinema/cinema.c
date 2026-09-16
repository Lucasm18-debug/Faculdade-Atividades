#include <stdio.h>

int main() {

    int mat[3][3];
    int i, j;
    int livres = 0;
    int ocupadas = 0;

    printf("Digite 0 para poltrona livre e 1 para poltrona ocupada:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);

            if (mat[i][j] == 0) {
                livres++;
            } else if (mat[i][j] == 1) {
                ocupadas++;
            }
        }
    }

    printf("\nSituacao da sala:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }

        printf("\n");
    }

    printf("\nPoltronas livres: %d\n", livres);
    printf("Poltronas ocupadas: %d\n", ocupadas);

    return 0;
}

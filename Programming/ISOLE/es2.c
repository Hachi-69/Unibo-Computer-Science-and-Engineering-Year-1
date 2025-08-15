#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define mR 10
#define mC 10
#define numIsola 0

int main() {
    int mat[mR][mC];

    srand(time(0));

    for (int i = 0; i < mR; i++) {
        for (int j = 0; j < mC; j++) {
            mat[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < mR; i++) {
        for (int j = 0; j < mC; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int counter = 0;

    for (int i = 0; i < mR - 1; i++) {
        for (int j = 0; j < mC - 1; j++) {
            if (mat[i][j] == numIsola && mat[i][j + 1] == numIsola &&
                mat[i + 1][j] == numIsola && mat[i + 1][j + 1] == numIsola) {

                counter++;
                printf("Trovata isola: %d, %d\n", i, j);

                mat[i][j] = 1;
                mat[i][j + 1] = 1;
                mat[i + 1][j] = 1;
                mat[i + 1][j + 1] = 1;
            }
        }
    }
    printf("Ci sono %d isole\n", counter);

    return 0;
}

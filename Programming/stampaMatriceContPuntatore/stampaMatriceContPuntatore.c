#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define mR 3
#define mC 3

int main(){

    int mat[mR][mC];
    int(*ptrMat)[mR][mC];
    ptrMat = &mat;

    srand(time(0));

    for (int i = 0; i < mR; i++) {
        for (int j = 0; j < mC; j++) {
            mat[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < mR; i++) {
        for (int j = 0; j < mC; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for (int i = 0; i < mR; i++) {
        for (int j = 0; j < mC; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
    printf("\n\n");

    for (int j = 0; j < mC*mR; j++) {
            printf("%d ", *(**ptrMat+j));

            if ((j+1) % 3 == 0) {
                printf("\n");
            }
        }

    return 0;
}

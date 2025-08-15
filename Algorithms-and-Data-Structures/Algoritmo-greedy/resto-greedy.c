#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Funzione per scambiare due elementi */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Funzione di partizionamento */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* Funzione principale Quicksort */
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

/* Funzione per stampare un array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Algoritmo del resto (greedy, da migliorare) */
int resto(int R, int m[], int n) {
    int i;
    int count = 0;
    int original_R = R;

    quicksort(m, 0, n - 1);

    /* Ordino in ordine decrescente per usare il greedy */
    for (i = 0; i < n / 2; i++) {
        int temp = m[i];
        m[i] = m[n - 1 - i];
        m[n - 1 - i] = temp;
    }

    printf("Monete ordinate (decrescente): ");
    printArray(m, n);

    printf("Resto da erogare: %d\n", R);
    printf("Monete usate: ");

    for (i = 0; i < n; i++) {
        while (R >= m[i]) {
            R -= m[i];
            printf("%d ", m[i]);
            count++;
        }
    }

    printf("\n");

    if (R == 0) {
        printf("Numero minimo di monete: %d\n", count);
        return count;
    } else {
        printf("Impossibile erogare il resto %d con le monete disponibili.\n", original_R);
        return -1;
    }
}

/* Funzione main */
int main(int argc, char *argv[]) {
    int R, n, i;
    int *m;
    FILE *filein = stdin;

    if (argc != 2) {
        fprintf(stderr, "Invocare il programma con: %s input_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-") != 0) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    if (fscanf(filein, "%d %d", &R, &n) != 2) {
        fprintf(stderr, "Errore nella lettura di R e n\n");
        return EXIT_FAILURE;
    }

    m = malloc(n * sizeof(*m));
    assert(m != NULL);

    for (i = 0; i < n; i++) {
        if (fscanf(filein, "%d", &m[i]) != 1) {
            fprintf(stderr, "Errore durante la lettura della moneta %d di %d\n", i + 1, n);
            free(m);
            if (filein != stdin) fclose(filein);
            return EXIT_FAILURE;
        }
    }

    resto(R, m, n);
    free(m);
    if (filein != stdin) fclose(filein);

    return EXIT_SUCCESS;
}

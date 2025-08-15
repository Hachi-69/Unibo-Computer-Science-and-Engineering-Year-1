#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

/* Scambia il contenuto di `v[i]` e `v[j]` */
void swap(int *v, int i, int j)
{
    const int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* Applica la procedura "partition" al sottovettore v[start..end]
   (estremi inclusi). Ritorna la posizione `split` del pivot, tale che
   al termine di questa funzione si abbia:

   - v[start..split-1] <= v[split]

   - v[split+1..end] > v[split]

*/
int partition(int *v, int start, int end)
{
    int pivot = v[end];
    int i = start-1;
    for(int j=start; j<end-1; j++){
        if(compare(v[j],pivot) <= 0){
            i++;
            swap(&v,i,j);
        }
    }
    swap(&v,end,i+1);
    return i+1;
}

/* Ordina il sottovettore `v[start..end]` (estremi inclusi) invocando
   ricorsivamente l'algoritmo Quicksort. */
void quicksort(int *v, int start, int end)
{
    if(start<end){
        int x=partition(*v, start, end);
        quicksort(*v, start, x-1);
        quicksort(*v, x+1, end);
    }
}

/* Ordina l'array `v[]` di lunghezza `n` usando l'algoritmo
   Quicksort. Questa funzione fa partire la ricorsione chiamando
   `quicksort()` con i parametri appropriati. Lo scopo di questa
   funzione è di nascondere i dettagli implementativi dell'algoritmo
   Quicksort, in particolare la necessità di passare gli indici degli
   estremi del sottovettore da ordinare. Questa tecnica prende il nome
   di "funzione trampolino". */
void sort(int *v, int n)
{
    quicksort(v, 0, n-1);
}

void print_array(const int *v, int n)
{
    int i;

    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]");
}

/* Restituisce un valore casuale compreso tra a e b (estremi inclusi) */
int randab(int a, int b)
{
    return a + rand() % (b-a+1);
}

/* Permuta il contenuto dell'array v[] in modo casuale. Per fare
   questo:

   - Si scambia v[0] con uno elemento casuale scelto in v[0..n-1].

   - Si scambia v[1] con un elemento casuale scelto in v[1..n-1].

   - ...

   - Si scambia v[i] con un elemento casuale scelto in v[i..n-1].

   - ...

   È possibile dimostrare che questo procedimento, applicato fino alla
   fine, produce una permutazione casuale (random shuffle) di v[].
*/
void random_shuffle(int *v, int n)
{
    int i;

    for (i=0; i<n-1; i++) {
        const int j = randab(i, n-1);
        const int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

/* Restituisce un intero < 0 se *p1 è minore di *p2 (interpretati come
   interi), 0 se sono uguali, > 0 se il primo è maggiore del
   secondo. */
int compare(const void *p1, const void *p2)
{
    const int v1 = *(const int*)p1;
    const int v2 = *(const int*)p2;
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* Confronta il contenuto di due array v1 e v2 di lunghezza n;
   restituisce l'indice del primo elemento il cui valore differisce
   nei due array, oppure -1 se gli array hanno lo stesso contenuto */
int compare_vec(const int *v1, const int *v2, int n)
{
    int i;
    for (i=0; i<n; i++) {
        if (v1[i] != v2[i])
            return i;
    }
    return -1;
}

/* Ordina l'array v[] di lunghezza n. Confronta il risultato
   dell'ordinamento con quello prodotto dalla funzione qsort() della
   libreria standard C. Restituisce true (nonzero) se il test ha
   successo, 0 altrimenti. */
int test(int *v, int n)
{
    int result;
    int *tmp = (int*)malloc(n * sizeof(*tmp));
    clock_t tstart, elapsed;
    int diff;

    assert(tmp != NULL); /* evita un warning con VS */
    memcpy(tmp, v, n*sizeof(*v));
    qsort(tmp, n, sizeof(*tmp), compare);
    tstart = clock();
    sort(v, n);
    elapsed = clock() - tstart;
    diff = compare_vec(v, tmp, n);
    if (diff < 0) {
        printf("Test OK (%f seconds)\n", ((double)elapsed) / CLOCKS_PER_SEC);
        result = 1;
    } else {
        printf("Test FALLITO: v[%d]=%d, atteso=%d\n", diff, v[diff], tmp[diff]);
        result = 0;
    }
    free(tmp);
    return result;
}

/* ATTENZIONE: questa macro produce il valore corretto SOLO se v[] è
   un array dichiarato sullo stack (quindi NON con malloc()). La
   macro DEVE essere chiamata all'interno di un blocco in cui è stato
   dichiarato v[] */
#define ARRAY_LEN(v) (sizeof(v)/sizeof(v[0]))

int main( void )
{
    int v1[] = {0, 8, 1, 7, 2, 6, 3, 5, 4};
    int v2[] = {0, 1, 0, 6, 10, 10, 0, 0, 1, 2, 5, 10, 9, 6, 2, 3, 3, 1, 7};
    int v3[] = {-1, -3, -2};
    int v4[] = {2, 2, 2};
    int v5[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    test(v1, ARRAY_LEN(v1));
    test(v2, ARRAY_LEN(v2));
    test(v3, ARRAY_LEN(v3));
    test(v4, ARRAY_LEN(v4));
    test(v5, ARRAY_LEN(v5));

    return EXIT_SUCCESS;
}

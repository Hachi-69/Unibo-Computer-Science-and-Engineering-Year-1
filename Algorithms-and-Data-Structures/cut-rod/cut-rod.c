#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* La lunghezza massima è 999 */
#define N 1000

/* Sebbene l'uso di variabili globali sia considerato (a ragione) una
   cattiva pratica di programmazione, la soluzione proposta le
   utilizza per semplificare l'interfaccia delle funzioni. Questo è
   giustificato dalla relativa semplicità di questo programma. Chi lo
   desidera può ristrutturare il codice trasformando le variabili
   globali in parametri da passare alle funzioni. */

double p[N];    /* p[i] è il prezzo di vendita di un segmento lungo
                   i, i=1..n; p[0] non viene usato. */
int n;          /* lunghezza dell'asta da tagliare. */
double r[N];    /* r[j] è il massimo guadagno che è possibile ottenere
                   tagliando un'asta lunga j, j=0..n. */
int s[N];       /* s[j] è la lunghezza della sezione che viene
                   tagliata per ultima per ottenere il guadagno
                   massimo r[j] del problema P(j). s[0] non viene
                   usato. */

/* Legge l'input dal file `filein`. Il formato dell'input è spiegato
   nei commenti iniziali. */
void init( FILE *filein )
{
    double val;
    p[0] = 0.0; /* p[0] non viene usato, quindi è inizializzato ad un
                   valore arbitrario. */
    n = 0;
    while (1 == fscanf(filein, "%lf", &val)) {
        n++;
        assert(n < N);
        p[n] = val;
    }
}

/* Determina la soluzione del problema "cut rod". Restituisce il
   guadagno massimo. */
double solve(void)
{
    int j, i;
    double q, current;

    r[0] = 0.0; /* Guadagno nullo per asta lunga 0 */

    for (j = 1; j <= n; j++) {
        q = -1.0;
        for (i = 1; i <= j; i++) {
            current = p[i] + r[j - i];
            if (current > q) {
                q = current;
                s[j] = i; /* Memorizza la lunghezza del primo taglio */
            }
        }
        r[j] = q;
    }

    return r[n];
}


/* Stampa la soluzione ottima trovata. */
void print(void)
{
    int length;

    printf("Guadagno massimo: %.2f\n", r[n]);
    printf("Tagli: ");

    length = n;
    while (length > 0) {
        printf("%d ", s[length]);
        length -= s[length];
    }
    printf("\n");
}



int main( int argc, char *argv[] )
{
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

    init( filein );
    /* Il cast a `void` serve per evitare warning da parte di
       compilatori particolarmente zelanti che segnalano che il valore
       di ritorno di `solve()` non viene usato. GCC non segnala alcun
       warning, quindi il cast a `void` è da considerare
       facoltativo. */
    (void)solve( );
    print( );
    if (filein != stdin) fclose(filein);

    return EXIT_SUCCESS;
}

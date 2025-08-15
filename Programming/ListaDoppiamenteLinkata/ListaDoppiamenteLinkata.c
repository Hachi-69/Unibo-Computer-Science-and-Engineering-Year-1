#include <stdlib.h>
#include <stdio.h>
#include <time.h>  // Per srand() e time()

typedef struct Numero {
    int n;
    struct Numero *next;
    struct Numero *prev;
} Numero;

typedef Numero *Pnumero;

int main() {
    Pnumero testa = NULL;

    // Inizializzare il generatore di numeri casuali
    srand(time(NULL));  // Usato per ottenere numeri diversi ogni volta

    int num_elementi = rand() % 10 + 1;

    StampaLista(testa);

    while(1==1){

        StampaLista(testa);
    }
    return 0;
}

void Aggiungi(Pnumero *t, int n) {
    Pnumero nuovo = (Pnumero)malloc(sizeof(Numero));
    nuovo->n = n;
    nuovo->next = *t;
    *t = nuovo;
}

// Funzione per stampare la lista
void StampaLista(Pnumero t) {
    Pnumero temp = t;
    while (temp != NULL) {
        printf("%d -> ", temp->n);
        temp = temp->next;
    }
    printf("NULL\n");
}


















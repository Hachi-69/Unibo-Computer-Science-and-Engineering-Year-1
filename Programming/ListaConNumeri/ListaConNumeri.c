#include <stdlib.h>
#include <stdio.h>
#include <time.h>  // Per srand() e time()

typedef struct Numero {
    int n;
    struct Numero *next;
} Numero;

typedef Numero *Pnumero;

int main() {
    Pnumero testa = NULL;

    // Inizializzare il generatore di numeri casuali
    srand(time(NULL));  // Usato per ottenere numeri diversi ogni volta

    int num_elementi = rand() % 10 + 1;  // Numero casuale di elementi da 1 a 10
    printf("Numero casuale di elementi da inserire: %d\n", num_elementi);

    // Riempire la lista con numeri casuali
    RiempiLista(&testa, num_elementi);

    // Stampare la lista
    printf("Lista riempita: \n");
    StampaLista(testa);
    while(1==1){
        printf("Inserisci un numero da cancellare: ");
        int n=NULL;
        scanf("%d",&n);

        Canc(&testa,n);

        StampaLista(testa);
    }
    return 0;
}

void Canc(Pnumero *t, int n){
    if (*t==NULL)
        return;
    Pnumero temp,prev,elimina;
    prev=NULL;
    temp=*t;

    while(temp!=NULL){
        if(temp->n==n){
            if(prev==NULL){ //cancella primo elemento
                *t=temp->next;
            }else{
                prev->next=temp->next;
            }  //cancellazione in mezzo
            elimina=temp;
            temp=temp->next;

            elimina->next=NULL;
            free(elimina);
        }
        else{ //scorrimento
            prev=temp;
            temp=temp->next;
        }
    }
    return;
}

// Funzione per aggiungere un nuovo numero alla lista
void Aggiungi(Pnumero *t, int n) {
    Pnumero nuovo = (Pnumero)malloc(sizeof(Numero));
    nuovo->n = n;
    nuovo->next = *t;
    *t = nuovo;
}

// Funzione per riempire la lista con numeri casuali
void RiempiLista(Pnumero *t, int num_elementi) {
    for (int i = 0; i < num_elementi; i++) {
        int num_casuale = (rand() % 9) + 1;  // Numero casuale tra 1 e 9
        Aggiungi(t, num_casuale);
    }
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


















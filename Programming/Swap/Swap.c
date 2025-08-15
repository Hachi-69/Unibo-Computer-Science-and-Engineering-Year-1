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

    int num_elementi = 10;
    printf("Numero casuale di elementi da inserire: %d\n", num_elementi);

    // Riempire la lista con numeri casuali
    RiempiLista(&testa, num_elementi);

    // Stampare la lista
    printf("Lista riempita: \n");
    StampaLista(testa);

    Swap(&testa,8,2);

    StampaLista(testa);

    return 0;
}


void Swap(Pnumero *t, int a, int b){
    if(*t==NULL)
        return;
    Pnumero temp,tempA,tempB;
    temp=*t;
    tempA=NULL;
    tempB=NULL;
    Pnumero auxA=NULL,auxB=NULL,auxAN=NULL;

    while(temp->next!=NULL){
        if(temp->next->n==a){
            tempA=temp->next;
            auxA=temp;
            auxAN=tempA->next;
        }else if(temp->next->n==b){
            tempB=temp->next;
            auxB=temp;
        }
        temp=temp->next;
    }

    if(tempA!=NULL && tempB!=NULL){

        auxA->next=tempB;
        auxB->next=tempA;

        tempA->next=tempB->next;
        tempB->next=auxAN;
    }
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
        int num_casuale = i;
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

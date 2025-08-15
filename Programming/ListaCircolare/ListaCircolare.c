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

    for(int i=0; i<10; i++){
        int n = rand() % 10 + 1;
        inserimentoTesta(&testa,n);

        printf("%d ", n);
    }
    printf("\n\n");
    StampaLista(testa);

    for(int i=0; i<10; i++){
        int c=NULL;
        scanf("%d", c);
        CancListaCircolare(&testa, c);
        StampaLista(testa);
    }
    StampaLista(testa);
    return 0;
}
void CancListaCircolare(Pnumero *t, int n){
    if (*t==NULL)
        return;
    Pnumero temp,prev,elimina;
    prev=NULL;
    temp=*t;

    while(temp->next!=*t){
        if(temp->n==n){
            if(prev==NULL){ //cancella primo elemento
                *t=NULL;
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

void inserimentoTesta(Pnumero *t, int n){
    Pnumero temp=*t,nuovo;

    nuovo=(Pnumero)malloc(sizeof(Numero));
    if(nuovo==NULL)
        return;
    nuovo->n=n;
    nuovo->next=NULL;

    if(*t==NULL){
        *t=nuovo;
        nuovo->next=nuovo;
        return;
    }
    while(temp->next!=*t){
        temp=temp->next;
    }
    temp->next=nuovo;
    nuovo->next=*t;
    *t=nuovo;
    return;
}

void StampaLista(Pnumero t) {
    if (t == NULL) {
        printf("Lista vuota\n");
        return;
    }

    Pnumero temp = t;
    do {
        printf("%d -> ", temp->n);
        temp = temp->next;
    } while (temp != t);  // Quando torniamo al nodo iniziale, fermiamo la stampa

    printf("(Testa)\n");
}

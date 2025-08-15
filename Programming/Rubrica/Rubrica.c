#include <stdio.h>
#include <stdlib.h>

typedef struct Contatto {
    char *tel;
    char *nome;
    int pri;
    struct Contatto *next;
}Contatto;
typedef Contatto *PContatto;

int main(){
    PContatto rubrica;
    InitLista(&rubrica);

    /*InserisciCoda(&rubrica,"michi","4");
    InserisciTesta(&rubrica,"Luca","1");
    InserisciCoda(&rubrica,"gab","2");
    InserisciTesta(&rubrica,"umbi","3");*/

    InserisciConPriorita(&rubrica,1,"a","1");
    InserisciConPriorita(&rubrica,2,"a","2");
    InserisciConPriorita(&rubrica,3,"a","3");
    InserisciConPriorita(&rubrica,2,"a","4");
    InserisciConPriorita(&rubrica,1,"a","5");
    InserisciConPriorita(&rubrica,3,"a","6");
    InserisciConPriorita(&rubrica,2,"a","7");

    StampaLista(rubrica);

    return 0;
}

void InserisciConPriorita(PContatto *lis, int pri, char *nome, char *tel){
    PContatto paux,temp;

    paux=(PContatto)malloc(sizeof(Contatto));
    temp=(PContatto)malloc(sizeof(Contatto));
    temp=*lis;

    if(paux==NULL)
        exit(1);
    paux->pri=pri;
    paux->nome=nome;
    paux->tel=tel;
    paux->next=NULL;
    if(*lis==NULL){
        *lis=paux;
    }else{
        while(temp->next!=NULL){
            if(temp->pri > paux->pri){
                paux->next=temp->next;
                temp->next=paux;
            }
            temp=temp->next;
        }
        paux->next=NULL;
        temp->next=paux;
    }
}

void TrovaPriorita(int priorita, PContatto temp, PContatto paux){
    while(temp->next->pri!=priorita){
        temp=temp->next;
    }
    paux->next=temp->next;
    temp->next=paux;
}

void InserisciCoda(PContatto *lis, char *nome, char *tel){

    PContatto temp, ultimo;
    temp=(PContatto)malloc(sizeof(Contatto));
    if(temp==NULL)
        exit(1);
    temp->nome=nome;
    temp->tel=tel;
    temp->next=NULL;

    if(*lis==NULL){
        *lis=temp;
    }else{
        ultimo=*lis;
        while(ultimo->next!=NULL){
            ultimo=ultimo->next;
        }
        ultimo->next=temp;
    }
}

void StampaLista(PContatto lis) {
    PContatto temp = lis;
    while (temp != NULL) {
        printf("Priorità: %d, Nome: %s, Telefono: %s\n",temp->pri, temp->nome, temp->tel);
        temp = temp->next;
    }
}

void InserisciTesta(PContatto *lis, char *nome, char *tel){

    PContatto temp;
    temp=(PContatto)malloc(sizeof(Contatto));

    if(temp==NULL)
        exit(1);
    temp->nome=nome;
    temp->tel=tel;
    temp->next=*lis;
    *lis=temp;
}

void InitLista(PContatto *lis){
    *lis = NULL;
}

int Empty(PContatto lis){
    return(lis==NULL? printf("Rubrica vuota\n") : printf("Rubrica NON vuota\n"));
}

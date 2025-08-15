#include <stdio.h>
#include <stdlib.h>

// Definizione del nodo
typedef struct Pnumero {
    int n;               // Il valore del nodo
    struct Pnumero* next; // Puntatore al nodo successivo
} Pnumero;

// Definizione della pila
typedef struct {
    Pnumero* top; // Puntatore al primo nodo della pila
} Pila;

int main() {
    Pila pila;
    init(&pila); // Inizializza la pila

    push(&pila, 10); // Aggiungi 10 alla pila
    push(&pila, 20); // Aggiungi 20 alla pila
    push(&pila, 30); // Aggiungi 30 alla pila

    printf("Elemento in cima alla pila: %d\n", top(&pila)); // Mostra l'elemento in cima (30)

    printf("Rimosso dalla pila: %d\n", pop(&pila)); // Rimuove l'elemento in cima (30)
    printf("Elemento in cima alla pila: %d\n", top(&pila)); // Mostra l'elemento in cima (20)

    pop(&pila); // Rimuove 20
    pop(&pila); // Rimuove 10

    if (isEmpty(&pila)) {
        printf("La pila è vuota!\n");
    }

    return 0;
}

void init(Pila* pila) {
    pila->top = NULL; // Impostiamo la pila come vuota
}

int isEmpty(Pila* pila) {
    return pila->top == NULL; // La pila è vuota se il puntatore top è NULL
}

void push(Pila* pila, int value) {
    Pnumero* newNode = (Pnumero*)malloc(sizeof(Pnumero)); // Creiamo un nuovo nodo
    if (newNode == NULL) { // Verifichiamo se la memoria è stata allocata correttamente
        printf("Memoria insufficiente!\n");
        return;
    }
    newNode->n = value; // Impostiamo il valore del nodo
    newNode->next = pila->top; // Il nuovo nodo punta al nodo corrente in cima alla pila
    pila->top = newNode; // La cima della pila ora è il nuovo nodo
}

int pop(Pila* pila) {
    if (isEmpty(pila)) {
        printf("La pila è vuota!\n");
        return -1; // Restituiamo un valore indicativo di errore
    }

    Pnumero* temp = pila->top; // Salviamo il nodo da rimuovere
    int value = temp->n; // Salviamo il valore del nodo

    pila->top = pila->top->next; // La cima della pila si sposta al nodo successivo
    free(temp); // Libera la memoria del nodo rimosso
    return value; // Restituisce il valore del nodo rimosso
}

int top(Pila* pila) {
    if (isEmpty(pila)) {
        printf("La pila è vuota!\n");
        return -1; // Restituiamo un valore indicativo di errore
    }

    return pila->top->n; // Restituiamo il valore in cima alla pila
}


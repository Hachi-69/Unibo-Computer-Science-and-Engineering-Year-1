#include <stdio.h>
#include <stdlib.h>

// Definizione del nodo
typedef struct Pnumero {
    int n;               // Il valore del nodo
    struct Pnumero* next; // Puntatore al nodo successivo
} Pnumero;

// Definizione della coda
typedef struct {
    Pnumero* front; // Puntatore alla testa della coda (dove si rimuovono gli elementi)
    Pnumero* rear;  // Puntatore alla coda della coda (dove si aggiungono gli elementi)
} Coda;

int main() {
    Coda coda;
    init(&coda); // Inizializza la coda

    enqueue(&coda, 10); // Aggiungi 10 alla coda
    enqueue(&coda, 20); // Aggiungi 20 alla coda
    enqueue(&coda, 30); // Aggiungi 30 alla coda

    printf("Elemento in testa alla coda: %d\n", front(&coda)); // Mostra l'elemento in testa (10)

    printf("Rimosso dalla coda: %d\n", dequeue(&coda)); // Rimuove l'elemento in testa (10)
    printf("Elemento in testa alla coda: %d\n", front(&coda)); // Mostra l'elemento in testa (20)

    dequeue(&coda); // Rimuove 20
    dequeue(&coda); // Rimuove 30

    if (isEmpty(&coda)) {
        printf("La coda è vuota!\n");
    }

    return 0;
}

void init(Coda* coda) {
    coda->front = NULL; // La coda è inizialmente vuota
    coda->rear = NULL;  // La coda è inizialmente vuota
}

int isEmpty(Coda* coda) {
    return coda->front == NULL; // La coda è vuota se il puntatore front è NULL
}

void enqueue(Coda* coda, int value) {
    Pnumero* newNode = (Pnumero*)malloc(sizeof(Pnumero)); // Creiamo un nuovo nodo
    if (newNode == NULL) { // Verifichiamo se la memoria è stata allocata correttamente
        printf("Memoria insufficiente!\n");
        return;
    }
    newNode->n = value;  // Impostiamo il valore del nodo
    newNode->next = NULL; // L'elemento finale non ha un nodo successivo

    if (isEmpty(coda)) { // Se la coda è vuota, entrambi front e rear saranno il nuovo nodo
        coda->front = newNode;
        coda->rear = newNode;
    } else {
        coda->rear->next = newNode; // Il nodo in coda punta al nuovo nodo
        coda->rear = newNode; // La coda ora è il nuovo nodo
    }
}

int dequeue(Coda* coda) {
    if (isEmpty(coda)) {
        printf("La coda è vuota!\n");
        return -1; // Restituiamo un valore indicativo di errore
    }

    Pnumero* temp = coda->front; // Salviamo il nodo da rimuovere
    int value = temp->n;         // Salviamo il valore del nodo

    coda->front = coda->front->next; // La testa della coda si sposta al nodo successivo
    if (coda->front == NULL) { // Se la coda diventa vuota, dobbiamo anche resettare il rear
        coda->rear = NULL;
    }
    free(temp); // Libera la memoria del nodo rimosso
    return value; // Restituisce il valore del nodo rimosso
}

int front(Coda* coda) {
    if (isEmpty(coda)) {
        printf("La coda è vuota!\n");
        return -1; // Restituiamo un valore indicativo di errore
    }

    return coda->front->n; // Restituiamo il valore in testa alla coda
}

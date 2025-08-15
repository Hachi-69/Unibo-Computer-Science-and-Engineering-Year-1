#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Crea un nuovo nuovo oggetto nodo contenente valore `v`. I puntatori
   al successore e predecessore del nuovo nodo puntano a se stesso.
   Trattandosi di una funzione ad uso interno (non è elencata
   nell'interfaccia descritta nel file <list.h>), è dichiarata
   "static" in modo che non sia visibile esternamente a questo file
   sorgente. */
static ListNode *list_new_node(int v)
{
    ListNode *r = (ListNode *)malloc(sizeof(ListNode));
    assert(r != NULL); /* evitiamo un warning con VS */
    r->val = v;
    r->succ = r->pred = r;
    return r;
}

/* Restituisce l'indirizzo di memoria della sentinella di `L` */
ListNode *list_end(const List *L)
{
    assert(L != NULL);
    return L->sentinel;
}

List *list_create( void )
{
    List *L = (List*)malloc(sizeof(List));
    assert(L != NULL);

    L->length = 0;
    L->sentinel = list_new_node(0); /* il valore contenuto nel nodo sentinella è irrilevante */
    return L;
}

int list_length(const List *L)
{
    assert(L != NULL);

    return L->length;
}



void list_clear(List *L)
{
    assert(L != NULL);
    if(!list_is_empty(L)){
        for(int i=0; i<=list_length(L); i++){
            free(list_nth_element(L,i));
        }
        L->sentinel->pred=L->sentinel;
        L->sentinel->succ=L->sentinel;
    }
}

void list_destroy(List *L)
{
    list_clear(L);
    free(L->sentinel);
    free(L);
}

/* Nota: questa funzione assume che `ListInfo` sia il tipo "int" */
void list_print(const List *L)
{
    const ListNode *node;

    assert(L != NULL);

    printf("(");
    for (node = list_first(L); node != list_end(L); node = list_succ(node)) {
        printf("%d ", node->val);
    }
    printf(")\n");
}

int list_is_empty(const List *L)
{
    assert(L != NULL);

    return (list_first(L) == list_end(L));
}

ListNode *list_search(const List *L, ListInfo k)
{
    ListNode *temp=L->sentinel;
    assert(L != NULL);

    for(int i=0; i<=list_length(L); i++){
        if(temp->val==k){
            return temp;
        }
        temp=temp->succ;
    }

    return L->sentinel;
}

ListNode *list_first(const List *L)
{
    assert(L != NULL);

    return L->sentinel->succ;
}

ListNode *list_last(const List *L)
{
    assert(L != NULL);

    return L->sentinel->pred;
}

/*dati due nodi n1, n2. rende n2 il
successore di n1*/
static void listJoin(ListNode *n1, ListNode *n2){
    n1->succ = n2;
    n2->pred = n1;
}
/* Inserisce un nuovo nodo contenente k all'inizio della lista */
void list_add_first(List *L, ListInfo k)
{
    assert(L != NULL);

    ListNode *succ, *new_node;
    succ = L->sentinel->succ;
    new_node = list_new_node(k);

    listJoin(L->sentinel,new_node);
    listJoin(new_node,succ);
    L->length++;

}

/* Inserisce un nuovo nodo contenente k alla fine della lista */
void list_add_last(List *L, ListInfo k)
{
    assert(L != NULL);
    ListNode *pred, *new_node;
    pred = L->sentinel->pred;
    new_node = list_new_node(k);

    listJoin(pred,new_node);
    listJoin(new_node,L->sentinel);
    L->length++;
}

/* Rimuove il nodo n dalla lista L */
void list_remove(List *L, ListNode *n)
{
    assert(L != NULL);
    assert(n != NULL);
    assert(n != list_end(L));
    /* [TODO] */
}

ListInfo list_remove_first(List *L)
{
    assert( !list_is_empty(L) );
    /* [TODO] */
    return -1; /* Sostituire con il valore di ritorno corretto */
}

ListInfo list_remove_last(List *L)
{
    assert( !list_is_empty(L) );
    /* [TODO] */
    return -1; /* Sostituire con il valore di ritorno corretto */
}

ListNode *list_succ(const ListNode *n)
{
    assert(n != NULL);

    return n->succ;
}

ListNode *list_pred(const ListNode *n)
{
    assert(n != NULL);

    return n->pred;
}

ListNode *list_nth_element(const List *L, int n)
{
    /* [TODO] */
    return NULL; /* Sostituire con il valore di ritorno corretto */
}

void list_concat(List *L1, List *L2)
{
    assert(L1 != NULL);
    assert(L2 != NULL);

    /* [TODO] */
}

int list_equal(const List *L1, const List *L2)
{
    assert(L1 != NULL);
    assert(L2 != NULL);

    /* [TODO] */
    return -1; /* Sostituire con il valore di ritorno corretto */
}

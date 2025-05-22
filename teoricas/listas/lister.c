//
//
// Lista de enteros ordenada y sin repetidos, version iterativa
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int isEmpty(const List l) {
    return l==NULL;
}

/*
 * 1 si el elemento está en la lista
 */
int belongs(const List l, int elem) {
    // Podemos usar l directamente, pero arroja warning por ser const
    List aux = l;
    while( aux != NULL && aux->head <= elem) {
        if ( aux->head == elem) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

int size(const List l) {
    int n=0;
    for(List aux=l; aux !=NULL; aux=aux->tail) {
        n++;
    }
    return n;
}


List add(List l, int elem) {
    // Al ser iterativo debemos ir guardando el anterior, para enlazarlo con el nuevo nodo
    List prev, curr = l;
    // Avanzamos hasta encontrar donde insertar el elemento
    while( curr != NULL && curr->head < elem) {
        prev = curr;
        curr = curr->tail;
    }
    // curr apunta al elemento encontrado, al primero que es mayor a element o a NULL
    if (curr!=NULL && curr->head == elem) {
        return l;	// ya estaba
    }
    List aux = malloc(sizeof( struct node ));
    aux->head = elem;
    aux->tail = curr;

    // Hay que considerar el caso especial en el cual se inserta delante del primero o la lista es vacia
    if ( curr == l)
        l = aux;
    else
        prev->tail = aux;

    return l;
}

List delete(List l, int elem) {
    // Al ser iterativo debemos ir guardando el anterior, para enlazarlo con el siguiente al que hay que borrar
    List prev, curr = l;
    // Avanzamos hasta encontrar el elemento a borrar o detectar que no esta
    while( curr != NULL && curr->head < elem) {
        prev = curr;
        curr = curr->tail;
    }
    // curr apunta al elemento encontrado, al primero que es mayor a element o a NULL
    if (curr==NULL || curr->head > elem) {
        return l;	// no estaba
    }
    List aux = curr->tail;
    free(curr);

    // Hay que considerar el caso especial en el cual se borra el primero
    if ( curr == l)
        l = aux;
    else
        prev->tail = aux;

    return l;
}

int head(const List l) {
    if (isEmpty(l)) {
        fprintf(stderr, "Invocación a head con lista vacía");
        exit(1);
    }
    return l->head;
}

List tail(const List l) {
    if (isEmpty(l)) {
        fprintf(stderr, "Invocación a tail con lista vacía");
        exit(1);
    }
    return l->tail;
}

void freeList(List l) {
    while (l != NULL) {
        List aux = l->tail;
        free(l);
        l = aux;
    }
}

#define BLOCK 10
int * toArray( List l) {
    // Esta ya era iterativa
    if ( l==NULL) {
        return NULL;
    }
    int * ans = NULL;
    int i;
    for(i=0; !isEmpty(l); i++, l = tail(l)) {
        if ( i % BLOCK == 0) {
            ans = realloc(ans, (i + BLOCK) * sizeof(*ans));
        }
        ans[i] = head(l);
    }
    ans = realloc(ans, i * sizeof(*ans));
    return ans;
}


int get(const List l, unsigned int idx) {
    List aux = l;
    while(aux != NULL && idx > 0) {
        aux = aux->tail;
        idx--;
    }
    if ( aux == NULL) {
        fprintf(stderr, "get: índice fuera de rango");
        exit(1);
    }
    return aux->head;
}
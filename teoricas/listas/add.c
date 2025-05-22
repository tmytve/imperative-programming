#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        tList aux = malloc(sizeof(tNode));
    struct Node *tail;
} tNode;

typedef tNode* tList;
//Agregar elemento en lista ordenada ascendente:
tList add(tList l, int elem){
    if (l == NULL){
        tList aux = malloc(siEof(tNode));
        aux->head = elem;
        aux->tail = l;
        return aux;
    }

    if (elem = l->head){
        return l;
    }

    l->tail = add(l->tail, elem); //recursividad
    return l;
}
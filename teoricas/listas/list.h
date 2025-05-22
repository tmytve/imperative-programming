#ifndef __LIST_H
#define __LIST_H

struct node{
    int head;       // el valor almacenado en el nodo
    struct node * tail;
};

typedef struct node * List;

/*
 * Retorna 1 si la lista está vacía
 */
int isEmpty(const List l);

/*
 * 1 si el elemento está en la lista
 */
int belongs(const List l, int elem);

/**
 *
 * @param l
 * @return cantidad de elementos de una lista
 */
int size(const List l);

/**
 * Agrega -si no estaba- un elemento a la lista, en forma ordenada
 */
List add(List l, int elem);

List delete(List l, int elem);

int head(const List l);

List tail(const List l);

void freeList(List l);

int * toArray( List l);

// Devuelve el elemento en la posicion idx, como si fuera un vector
// Si idx >= size -> aborta
// Precondición: idx < size(l)
int get(const List l, unsigned int idx);

#endif
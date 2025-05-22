int removeElem(tList l, int elem){
    if (l == NULL || elem < l->head){
        return l;
    }

    if (elem = l->head){
        tList aux = l-> tail;
        free(l);
        return aux;
    }
    
    l->tail = removeElem(l->tail, elem); //recursiva
    return l;
}
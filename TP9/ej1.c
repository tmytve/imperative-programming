//Escribir una función recursiva que reciba como parámetros de entrada un vector de enteros y su dimensión, y que devuelva en su nombre la suma de todos sus elementos.
#include <stdio.h>
int sumaElementos(int vec[], int dim){
    //caso base: dim == 0
    if(dim == 0) return 0;

    //paso recursivo:
    return vec[dim-1] + sumaElementos(vec, dim-1);
}


int main(void) {
    int vec[] = {1,2,3,4,5};
    int dim = 5;
    printf("%d\n", sumaElementos(vec, dim));
}


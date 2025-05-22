/*Hacer una función que lea números enteros de entrada estándar (los lee con getint) y los
guarde en un arreglo. El arreglo debe crecer a medida que se necesita. La carga en el arreglo
finaliza cuando un valor se repite por primera vez.
Tener en cuenta:
● Modularizar cuando se pueda
● Fijarse en qué puntos del código hay que reasignar memoria*/

#include "getnum.h"
#include <stdio.h>
#include <stdlib.h>
int pertenece(int vec[], int dim, int x);
int *cargarNumeros(int *dim);

int main(void) {
    int dim;
    int *arr;
    arr = cargarNumeros(&dim);
    for (int i = 0; i < dim; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}

int *cargarNumeros(int *dim){
    (*dim) = 0;
    int *arr = NULL;
    int num;
    int incluido = 1;
    while (incluido){
        num = getint("Ingrese un numero: ");
        if (!pertenece(arr, *dim, num)){
            arr = realloc(arr, (*dim + 1) * sizeof(int)); //corregir eficiencia de memoria con bloques!!!
            arr[*dim] = num;
            (*dim)++;
        }else{
            incluido = 0;
        }
    }
    return arr;
}


int pertenece(int vec[], int dim, int x){
    for (int i = 0; i < dim; i++){
        if (vec[i] == x){
            return 1;
        }
    }
    return 0;
}


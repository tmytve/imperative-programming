//Escribir una función que retorne un conjunto de números reales ingresados por el usuario en un arreglo. La cantidad de números no es constante sino que también debe ser solicitada al usuario. 

#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
double * leerNumeros(size_t dim);

int main(void) {
    int dim;
    do{
        dim = getint("Ingrese la cantidad de numeros: ");
    } while (dim <= 0);
    double * vec = leerNumeros(dim);
    
    for (int i = 0; i < dim; i++){
        printf("%.2f  ", vec[i]);
    }    

    free(vec);
    return 0;
}

double * leerNumeros(size_t dim){
    //Reservo memoria dinamica para el vector
    double * v = malloc(dim * sizeof(*v));

    //Invoco a getDouble dim veces y lo almaceno en el vector
    for (int i = 0; i < dim; i++){
        v[i] = getdouble("Ingrese el numero %d ", i+1);
    }
    //Retorno el vector
    return v;
}

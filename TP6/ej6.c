//Dado un arreglo ordenado ascendentemente se pide escribir una función que reciba como parámetro de entrada/salida el arreglo y como parámetro de entrada su dimensión y que lo devuelva desordenado, simulando la mezcla de un mazo de cartas o de un bolillero (en no más de 10 líneas). 

#include <stdio.h>
#include "random.h"
#define DIM 5
void desordena(int vec[], int dim);

int main(void) {
    int vec[DIM] = {3,4,5,6,7};
    desordena(vec, DIM);
    for (int i = 0; i < DIM; i++){
         printf("%d ", vec[i]);
    }
    printf("\n");

}

void desordena(int vec[], int dim){
    randomize();
    randNormalize();
    for (int i = 0; i < dim; i++){
        int r = randInt(0, dim);
        int temp = vec[i];
        vec[i] = vec[r];
        vec[r] = temp;
    }
    
}
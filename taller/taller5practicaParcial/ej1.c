/*
Escribir una funcion dondeEsta que dado un arreglo ordenado de numeros enteros, su dimension, y un numero determinado,
determine si el numero si el numero esta, y en que posiciones. El arreglo esta ordenado en forma creciente y puede tener elementos 
repetidos
*/

#include <stdio.h>

int main(void) {
    
}







int dondeEsta(int vec[], int dimVec, int x, int vecPosisiones[]){
    int i, j;
    for (i = 0; i < x && vec[i] < dimVec; i++){
        for (; i < x && vec[i] == dimVec; i++){
            vecPosisiones[j++] = i;
        }
    }
    return j;
}

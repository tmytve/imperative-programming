//Escribir la función readArray para leer desde la entrada estándar números positivos de tipo float y guardarlos en un arreglo ya creado. 
#define DIM 6
#include <stdio.h>
#include "getnum.h"
int readArray(int v[]);
void printArray(int v[]);
int main(void){
    int v[DIM];
    int elemCount = readArray(v);
    printArray(v);
   return 0;
}
int readArray(int v[]){
    int i, esPositivo;
    for (i = 0, esPositivo = 1; i < DIM && esPositivo; i++){
        int aux = getfloat("Ingrese un numero natural: ");
        if (aux <= 0){
            esPositivo = 0;
        }else{
            v[i] = aux;
        }
    }
    return i;
}

void printArray(int v[]){
    for (int i = 0; i < DIM; i++){
        printf("%d\t", v[i]);
    }
}

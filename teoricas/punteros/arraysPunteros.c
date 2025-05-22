/*
Escribir una funcion que reciba un vector de enteros y un numero y devuelva si el numero aparece en el vector
Implementarla usando notacion de vectores y notacion de punteros
*/
#include <stdio.h>
int isInVec(int *vec, int dim, int n);
int main(void) {
    int vec[] = {3, 1, 4};
    int n = 5;
    isInVec(vec, sizeof(vec)/sizeof(vec[0]), n);
    printf("El numero %d %s esta en el vector", n, isInVec? "": "no " );
}

int isInVec(int *vec, int dim, int n){
    while (*vec != -1){
        if (*vec == n){
            return 1;
        }
        vec++;
    }
    return 0;
}

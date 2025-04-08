// Indicar en cada uno de los siguientes ejemplos qué se está haciendo.
#include <stdio.h>
#define DIM 10
int main(void) {
    int pares[DIM], i;
    for (i=0; i<=DIM-1; ++i)
        pares[i]= 2 * (i+1);
    
}
/*
Dentro del bucle, pares[i] = 2 * (i + 1); asigna a cada posición del arreglo el correspondiente número par:
Para i = 0: 2 * (0+1) = 2.
Para i = 1: 2 * (1+1) = 4.
Y así sucesivamente hasta i = 9: 2 * (9+1) = 20.
De esta manera, el arreglo pares contendrá: {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}.
*/
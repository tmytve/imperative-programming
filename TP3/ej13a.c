//Dada una variable entera que indica el lado de un cuadrado, imprimir por salida estándar  dicho cuadrado en forma de asteriscos. 
// a) Resolverlo con dos ciclos anidados.

#include <stdio.h>
#include "../getnum.h"
int main(void) {
    int dimension = getint("Indique la dimension del cuadrado: ");

    for (int i = 0; i < dimension; i++)
    {
        printf("\n");
        for (int i = 0; i < dimension; i++){
            printf("*");
        }
    }
    printf("\n");
}

//Dada una variable entera que indica el lado de un cuadrado, imprimir por salida estándar  dicho cuadrado en forma de asteriscos.
// b) Resolverlo con un único ciclo for
#include <stdio.h>
#include "../getnum.h"
int main(void) {
    int dimension = getint("Ingrese la dimesion del cuadrado: ");

    for (int i = 1; i <= dimension*dimension; i++){
        if (i % dimension == 0)
        {
            printf("*\n");
        }
        else{
            printf("*");
        }
    }
}

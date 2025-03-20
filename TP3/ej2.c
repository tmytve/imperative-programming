/*
Leer dos caracteres desde la entrada estándar  e imprimir por salida estándar  si son iguales, si el primero es mayor o si el primero es menor, teniendo en cuenta su valor ASCII.
*/
#include <stdio.h>
#include "../getnum.h"

int main(void) {
    printf("Ingrese dos caracteres: ");
    unsigned char c1 = getchar(), c2 = getchar();
    if (c1==c2)
    {
        printf("El caracter '%c' es igual al caracter '%c'\n", c1, c2 );
    }
    else if (c1>c2)
    {
        printf("El caracter '%c' es mayor al caracter '%c'\n", c1, c2 );  
    }
    else{
        printf("El caracter '%c' es menor al caracter '%c'\n", c1, c2 );  
    }

}
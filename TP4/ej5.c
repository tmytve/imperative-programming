/*
Escribir una macro MAXIMO2 que recibiendo tres parámetros, asigne al tercer parámetro el mayor de los dos primeros. Utilizarla en un programa para verificar su correcto funcionamiento. (En no más de 5 líneas)
*/
#include <stdio.h>
#include "../getnum.h"
#define MAXIMO2(a,b,c) (c = ((a)>(b))? a : b)

int main(void) {
    int a, b, c;
    a = getint("a = ");
    b = getint("b = ");
    MAXIMO2(a, b, c);
    printf("c = %d\n", c);
}

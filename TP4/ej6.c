/*
Escribir la macro MAXIMO3 para determinar el mayor de 3 valores, usando la macro definida en el ejercicio anterior. (En no más de 10 líneas). Verificar su funcionamiento invocándola desde un programa.
*/
#include <stdio.h>
#include "../getnum.h"
#define MAXIMO2(a,b,c) (c = ((a)>(b))? a : b)
#define MAXIMO3(a,b,c,d) (d = ((a > b) && (a > c))? a : (((b > a) && (b > c))? b : c))

int main(void) {
    int a, b, c, d;
    a = getint("a = ");
    b = getint("b = ");
    c = getint("c = ");
    MAXIMO3(a, b, c, d);
    printf("d = %d\n", d);
}

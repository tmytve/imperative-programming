// Escribir una función que reciba tres parámetros de entrada de tipo entero y que devuelva en su nombre el mayor de ellos. (En 2 líneas)
int maximo3(int a, int b, int c){
    return ((a > b && a > c)? a : ((b > a && b > c)? b : c));
}



#include <stdio.h>
int main(void) {
    printf("%d\n", maximo3(5, 77, 23));
}

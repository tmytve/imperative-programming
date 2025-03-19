/*
Escribir un programa que lea dos enteros y a continuación imprima el promedio, la suma, el menor y el mayor de ellos (o indicar que son iguales). Usar el operador condicional.
*/

#include <stdio.h>
#include "../getnum.h"

int main(void) {
    int a, b; 
    a = getint("Escriba el primer numero: ");
    b = getint("Escriba el segundo numero: ");

    float promedio = (a+b)/2;
    printf("El promedio es: %f\n", promedio);
    printf("La suma de %d + %d es: %d\n",  a, b, a+b);
    int sonIguales = a==b;

    sonIguales ? printf("%d y %d son iguales\n", a,b) : printf("%d es mayor que %d\n", a>b ? a:b, a<b ? a:b);
}

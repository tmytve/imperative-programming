/*
Escriba un programa que lea de entrada estándar un número entero positivo y calcule la cantidad de bits en ‘1’ que contiene.

Por ejemplo:

Si el número es 1, imprime 1
Si el número es 64, imprime 1
Si el número es 229, imprime 5
*/
#include <stdio.h>
#include "../getnum.h" // ../getnum.c al compilar 
int main(void) {
    int num = getint("Escriba un numero natural: "); 
    int bits = 0;
    while (num > 0){
        if (num % 2 == 1){
            bits++;
        }
        num /= 2;
    }
    printf("# de unos = %d\n", bits);
}
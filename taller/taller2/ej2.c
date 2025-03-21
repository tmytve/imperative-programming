//Escribir un programa que lea un numero entero y obtenga la suma de sus cifras
#include <stdio.h>
#include "getnum.h"
int main(void) {
    long long int resultado = 0;
    int num = getint("Inserte un numero: ");
    while (num!=0)
    {
        //resultado += (num % 10);
        resultado += num%10;
        num = num/10;
    }
    printf("La suma de los digitos es %lld\n", resultado);
    return 0;
}

/*
Escribir una función que determine si un número es primo.
Debe devolver 1 si ES primo y 0 si NO LO ES.
*/
#include <stdio.h>
#include <math.h>
#include "getnum.h"
int esPrimo(int num);

int main(void) {
     int num = getint("Ingrese un numero: ");
     esPrimo(num);
     printf("El numero %d %ses primo\n", num, esPrimo(num) ? "": "no");
}

int esPrimo(int num){
    int raiz = sqrt(num);
    int flag = 1;
    for (int i = 2; i <= raiz; i++){
        if (num % i == 0){
            flag = 0;
        }
    }   
    return flag;
}

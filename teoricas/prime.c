#include <stdio.h>
#include "getnum.h"
#include <math.h>

int main(void){
    int esPrimo = 1;
    int n = getint("Ingrese un numero: ");
    int raiz = sqrt(n);

    for (int i = 2; i <= raiz; i++){
        if (n % i == 0){
            esPrimo = 0;
        }
    }
    printf("%d %s es primo\n", n,  esPrimo? "" : "no");    
}

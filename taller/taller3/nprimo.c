#include <stdio.h>
#include <math.h>
#include "getnum.h"
int esPrimo(int num);
int nPrimos(int num);

int main(void){
    int n = getint("Ingrese los primeros n primos que quiere: ");
    nPrimos(n);
    printf("\n");
}
int nPrimos(int n){
    int cantPrimos = 0;
        for (int i = 2; cantPrimos < n; i++){
            if (esPrimo(i)){
                cantPrimos++;
                printf("%d ", i);
            }
    }
    return 0;
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

#include <stdio.h>
#include <math.h>
#include "getnum.h"
int numerosAmigos(int a, int b);
int sumaDivisores(int num);
int main(void) {
    int n1 = getint("Ingrese el primer numero: ");
    int n2 = getint("Ingrese el segundo numero: ");
    printf("Los numeros %d y %d %s son amigos\n", n1, n2, numerosAmigos(n1,n2)? "" : "no");
    
}

int numerosAmigos(int a, int b){
    int sumaDivA = sumaDivisores(a);
    int sumaDivB = sumaDivisores(b);
    printf("%d , %d", sumaDivA, sumaDivB);
    if ((sumaDivA == b) && (sumaDivB == a)){
        return 1; 
    }else{
        return 0;
    }
    
}
int sumaDivisores(int num){
    int suma = 0;
    for (int i = 1; i <= num/2; i++){
        if (num % i == 0){
            suma += i;
        }
    }
    return suma;
    
}

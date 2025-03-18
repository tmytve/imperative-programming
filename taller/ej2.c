// dado tres numeros decidir cual es mayor utilizando un operador condicional
#include <stdio.h>
int main(void){
    int a = 3;
    int b = 5;
    int c = 7;

    int mayor = (a > b) ? ((a > c)? a : c):((b > c)? b : c) ; 
    printf("%d\n", mayor);  
}

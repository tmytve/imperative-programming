/*Escribir la función recursiva suma que reciba un único parámetro de entrada de tipo integer y devuelva en su nombre la suma de sus dígitos. Por ejemplo,  suma( 3498 ) devuelve 24*/
#include <stdio.h>
int sumaDigitosRecursiva(int num){
    //caso base: num == 0
    if(num == 0) return 0;

    //paso recursivo:
    return num%10 + sumaDigitosRecursiva(num/10);
}


int main(void) {
    printf("%d\n", sumaDigitosRecursiva(3498));
}

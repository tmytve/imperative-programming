/*
Escriba un programa que lea un entero no negativo ( cero o mayor ) y que calcule e imprima su factorial. En caso de ingresar un valor inválido, imprimir un cartel aclarando cuáles son los valores válidos. (En no más de 10 líneas)
*/
#include <stdio.h>
#include "../getnum.h"
int factorial(int num);
int main(void) {
    int num = getint("Escriba un numero mayor o igual a 0: ");
    factorial(num);
}

int factorial(int num){
    int total = 1;
    if (num == 0)
    {
        printf("El factorial de 0 es 1\n");
    }else if (num > 0){
        for (int i = 1; i <= num; i++)
        {
            total *= i;
        }
        printf("El factorial de %d es %d\n", num, total);
    }else{
        printf("El numero ingresado debe ser mayor o igual a 0\n");
    }
    return total;
}

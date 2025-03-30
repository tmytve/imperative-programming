/*
Escribir un programa que lea un número entero, y escriba por salida estándar  dicho número y un cartel indicando si es capicúa o no. (En no más de 10 líneas)
*/
//hay que guardar el numero en una variable, y luego compararlo con otra variable que lo guarde al reves, esto se logra dividiendo el numero por 10 y guardando los restos de dividirlo por 10 en otra variable
#include <stdio.h>
#include "../getnum.h"
int main(void) {
    int original = getint("Escriba un numero: ");
    int num = original, numeroInvertido = 0;
    while (num!=0){
        numeroInvertido = numeroInvertido * 10 + (num % 10);
        num /= 10;
    }
    printf("%d %s capicua\n", original , (original == numeroInvertido)? "es" : "no es");
}

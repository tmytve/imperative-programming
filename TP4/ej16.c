// EJERCICIO DE PARCIAL
//Escribir la macro DIVISOR que reciba dos números enteros (no necesariamente positivos) y retorne 1 si el segundo es divisor del primero y cero si no es divisor. No usar funciones auxiliares.

/*
Ejemplos de invocación:

int a, b = 10, c = 3;
a = DIVISOR(b,c); 	// a = 0 
a = DIVISOR(b,c-1);	// a = 1 
*/

#define DIVISOR(b, c) ((b % c == 0)? 1 : 0)

#include <stdio.h>
int main(void) {
    int a, b = 10, c = 3;
    a = DIVISOR(b,c); 	// a = 0 
    //a = DIVISOR(b,c-1);	// a = 1
    printf("%d\n", a);
}



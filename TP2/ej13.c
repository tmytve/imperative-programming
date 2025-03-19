/*
Escribir un programa que lea dos enteros, e imprima si el segundo es múltiplo del primero. Usar el operador condicional.
*/

#include <stdio.h>
#include "../getnum.h"

int main(void) {
    int a, b;
    a = getint("Escriba el primer numero: ");
    b = getint("Escriba el segundo numero: ");

    int esMult = b%a == 0;
    esMult? printf("%d es multiplo de %d\n", b, a) : printf("%d no es multiplo de %d\n", b, a);
    //preguntar que diferencia hay en que ponga un return 0 o que no lo ponga !!!!
}

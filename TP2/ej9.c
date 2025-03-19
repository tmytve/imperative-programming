// Leer un número entero positivo y escribir en la salida estándar 
// el valor de dicho número dividido por 2, usando decalaje de bits.
#include <stdio.h>
#include "../getnum.h"

int main(void) {
    int num = getint("Ingrese un número entero positivo: ");
    // Se usa el decalaje a la derecha para dividir por 2
    printf("La mitad de ese número es: %d\n", num >> 1);
    return 0;
}
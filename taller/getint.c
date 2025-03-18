#include <stdio.h>
#include "../getnum.h"

int main() {
    int numero = getint("Ingrese un número entero: ");
    printf("Número ingresado: %d\n", numero);
    return 0;
}

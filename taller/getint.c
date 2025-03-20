#include <stdio.h>
#include "../getnum.h"

int main() {
    int numero = getint("Ingrese un número entero: ");
    printf("Número ingresado: %d\n", numero);
    return 0;
}


//para compilar un archivo cuando uso el encabezado getnum.h se hace de la siguiente manera en la terminal:
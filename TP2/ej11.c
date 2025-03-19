/*
Leer dos caracteres desde la entrada estándar e imprimir en la salida estándar el de mayor valor ASCII, usando el operador condicional. Redireccionar la entrada de manera tal que getchar  lea desde el archivo entrada.txt.  Dicho archivo será escrito con un editor de texto sin formato y deberá tener el siguiente contenido:

a)ABCD
b) A
   B
   C
   D

c)A     B     (usando tabulador entre A y B)
*/
#include <stdio.h>
#include "../getnum.h"

int main(void) {
    unsigned char c1 = getchar(), c2 = getchar();
    
    int maxascii = (c1>c2)? c1 : c2;

    printf("El caracter con mayor valor ascii es %d\n", maxascii);

/*
el codigo funciona para los caracteres insertados en la terminal.
!!Preguntar como hacer para redireccionar la entrada al txt !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

}

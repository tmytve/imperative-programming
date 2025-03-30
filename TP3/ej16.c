/*
Dado un número entero positivo, imprimir por salida estándar  el equivalente en base binaria. El rango de números a considerar puede estar acotado
*/
#include <stdio.h>
#include "../getnum.h"

/*En la siguiente funcion recursiva lo que se logra es hacer el mecanismo de conversion de un numero decimal a uno binario, la funcion recibe un numero n, si este es mayor que 1 entonces se llama a si misma con el argumento de n/2 */
void imprimirBinario(int n){
    if (n > 1){
        imprimirBinario(n/2);
    }
    printf("%d", n%2);
}

int main(void) {
    int num = getint("Ingrese un numero: ");
    if (num == 0){
        printf("0\n");
    }else{
        imprimirBinario(num);
    }
    
    printf("\n");
    return 0;
}


/*
Por ejemplo, para n = 5:

imprimirBinario(5) llama a imprimirBinario(5/2) → imprimirBinario(2)
imprimirBinario(2) llama a imprimirBinario(2/2) → imprimirBinario(1)
imprimirBinario(1) no llama recursivamente porque 1 no es mayor que 1, y luego imprime 1 % 2, que es 1.
Al regresar a imprimirBinario(2), se imprime 2 % 2 = 0.
Luego, en imprimirBinario(5), se imprime 5 % 2 = 1.
La salida final es "101", que es la representación binaria de 5.

Cada llamada "apila" la operación, y al terminar la llamada recursiva (cuando llega al caso base), se van "desapilando" e imprimiendo los dígitos. Esa es la esencia de la recursión.
*/
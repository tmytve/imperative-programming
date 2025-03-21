#include <stdio.h>
#include "getnum.h"
int main(void) {
    float num = getfloat("Escribe un numero con decimal: ");
    int parteEntera = (int) num;
    float decimales = num - parteEntera;
    int suma = 0;
    int digito;
    while (decimales > 0)
    {
        decimales *= 10;
        digito = (int) decimales;
        suma+=digito;
        decimales-=digito;
    }


    printf("La suma de los digitos decimales es: %d\n", suma);
    return 0;
}
//el programa solo funciona para decimales potencia de dos ya que se utiliza el getfloat() que toma el punto flotante IEEE
//para que funcione con cualquier numero hay que hacerlo con getchar()
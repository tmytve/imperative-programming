#include <stdio.h>
int
main(void)
{
    int i, j, max;
    i = j = 2;
    max = (i>j? i : j) ;

    return 0;
}

//Errores al compilar:
//la variable I nunca fue declarada, la correcta es i
//'end' al final del programa no existe. se termina con un return 0;

/* pd: la variable max esta definida por una condicion, si i es mayor que
j entonces max = i.  Sino, (el else es :) max = j     */

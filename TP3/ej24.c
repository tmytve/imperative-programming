/*
Dado el siguiente código explicar DETALLADAMENTE el resultado obtenido al ejecutarlo
*/
#include <stdio.h>
int main(void){
    float a = 0.1;


    if (a == 0.1)
        printf("SON iguales\n");
    else
        printf("NO SON iguales: a vale %g que no es igual a 0.1\n",a);


    return 0;
}
/*
Al declarar:   float a = 0.1; el literal 0.1 es de tipo double, pero como a es float, el valor se convierte y se aproxima a 0.1 con menor precisión (por ejemplo, 0.10000000149011612 o similar, dependiendo del sistema).

Luego, en la comparación:   if (a == 0.1) el literal 0.1 se sigue interpretando como double. Cuando se compara el float (promovido a double) con el literal double 0.1, ambas representaciones no coinciden exactamente debido a la limitación de precisión del float.

Por ello, se evalúa como falso y se ejecuta la rama else, imprimiendo que a no es igual a 0.1, mostrando el valor aproximado de a.≈ 
*/
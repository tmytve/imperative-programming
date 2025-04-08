// Indicar en cada uno de los siguientes ejemplos qué se está haciendo
#include <stdio.h>

int main(void) {
    float reales[] = { 2.5, -3.7, -1, 0.34 };
    for(int i=0;i<sizeof(reales)/sizeof(reales[0]);i++)
        printf("reales[%d] = %g\n", i, reales[i] ); //imprime la posicion y el valor de cada elementod el array

    /*
        Output:
            reales[0] = 2.5
            reales[1] = -3.7
            reales[2] = -1
            reales[3] = 0.34
    */
}



/*
En esteganografía se ocultan valores en cada uno de los pixeles de una imagen. Para hacer este ocultamiento menos predecible se puede ocultar siguiendo una secuencia no correlativa de píxeles. En el esquema propuesto, se oculta entonces en los pixeles que correspondan según un salto elegido. Así, si el salto elegido es 2, se oculta en los pixeles de índices 0,2,4,6, etc. Cuando se llega al final de la cadena de píxeles, se sigue por los píxeles que faltan: los de índices 1, 3, 5, 7, etc.
Hacer una función que reciba un arreglo de píxeles y genere un nuevo arreglo de píxeles reordenado según el salto elegido para el ocultamiento de información.
*/

#include <stdio.h>
void salto(int vec[], int dimVec, int salto, int vecSalida[]);

int main() {
    int vec[] = {1, 2, 3, 4, 5, 6};
    int dimVec = 6;
    int vecSalida[6];

    salto(vec, dimVec, 2, vecSalida);

    printf("Vector salida: ");
    for (int i = 0; i < dimVec; i++) {
        printf("%d ", vecSalida[i]);
    }
    printf("\n");

    return 0;
}

void salto(int vec[], int dimVec, int salto, int vecSalida[]){
    int k = 0;
    for (int i = 0; i < salto; i++){
        for (int j = i; j < dimVec; j+=salto){
            vecSalida[k++] = vec[j];
        }
    }
}
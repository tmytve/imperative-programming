/*
Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos, ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1. La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros, también terminado en -1.

	Ejemplo: Dados v1 y v2 arreglos de enteros, se espera que la unión sea:
		v1 = {1,2,3,-1} y v2 = {2,3,4,-1}  →  unión = {1,2,3,4,-1}.
		v1 = {1,2,3,-1} y v2 = {1,2,3,-1}  →  unión = {1,2,3,-1}.

Recorrer una sola vez cada arreglo.
*/


#include <stdio.h>
#define DIM 10
void unirVectores(int vec1[], int vec2[], int vecFinal[], int dimVec1,  int dimVec2);
int main(void) {
    int v1[DIM] = {1, 2, 3, 9, 10, 23, -1};
    int v2[DIM] = {2, 2, 3, 4, 5, 6, 25, 30, -1};
    int vecFinal[DIM];
    unirVectores(v1, v2, vecFinal, DIM, DIM);
    for (int i = 0; vecFinal[i] != -1; i++){
        printf("%d  ", vecFinal[i]);
    }
    printf("-1\n");
    
}

void unirVectores(int vec1[], int vec2[], int vecFinal[], int dimVec1,  int dimVec2){
    int i = 0, j = 0, k = 0;
    while (vec1[i] != -1 && vec2[j] != -1){
        if (vec1[i] < vec2[j]){
            // Si el elemento actual de vec1 es menor, se copia en el vector final
            // y se incrementa i (para avanzar en vec1) y k (para pasar a la siguiente posición en vecFinal)
            vecFinal[k++] = vec1[i++];
        } else if (vec1[i] > vec2[j]){
            // Si el elemento actual de vec2 es menor, se copia en el vector final,
            // se incrementa j y k.
            vecFinal[k++] = vec2[j++];
        } else { // Son iguales: se copia uno solo y se avanzan ambos índices.
            vecFinal[k++] = vec1[i];
            i++;
            j++;
        }
    }
    // Si quedan elementos en vec1, se copian todos hasta encontrar -1.
    while (vec1[i] != -1) {
        vecFinal[k++] = vec1[i++];
    }
    // Si quedan elementos en vec2, se copian todos hasta encontrar -1.
    while (vec2[j] != -1) {
        vecFinal[k++] = vec2[j++];
    }
    // Se asigna -1 al final del vector final para indicar que es su terminador.
    vecFinal[k] = -1;
    // La función devuelve el número de elementos agregados (sin contar el -1 terminador).
}


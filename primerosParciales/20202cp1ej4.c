/*
Hacer una función depura que reciba 2 vectores de enteros y la dimensión de cada uno, y deje en el primer vector únicamente los números que no estén en el segundo vector.
Los 2 vectores están ordenados en forma ascendente, no contienen elementos repetidos
La función debe retornar además la nueva dimensión del vector

Ejemplo:
int v3[] = {1, 2, 3, 4, 5, 6, 7};
int v4[] = {2, 4, 5};
int dim3;
dim3 = depura(v3, 7, v4, 3);
for(int i=0; i < dim3; i++) 
   printf("%d ", v3[i]);         // imprime los números 1, 3, 6, 7

*/

#include <stdio.h>
int depura(int vec1[], int dimVec1, int vec2[], int dimVec2);
int main(void) {
    int v3[] = {1, 2, 3, 4, 5, 6, 7};
    int v4[] = {2, 4, 5};
    int dim3 = depura(v3, 7, v4, 3);
    for(int i=0; i < dim3; i++) 
        printf("%d ", v3[i]); // imprime: 1 3 6 7
}


int depura(int vec1[], int dimVec1, int vec2[], int dimVec2){
    int i = 0, j = 0, k = 0;

    while (1 < dimVec1 && j < dimVec2){
        if (vec1[i] < vec2[j]){
            vec1[k++] = vec1[i++];
        }else if (vec1[i] > vec2[j])
        {
            j++;
        }else{
            i++;
            j++;
        }
    }
    while (i < dimVec1)
    {
        vec1[k++] = vec1[i++];
    }
    
    return k;
}

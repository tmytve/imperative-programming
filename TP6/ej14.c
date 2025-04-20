/*Escribir la función contiene que reciba dos vectores de enteros y la dimensión de cada uno y retorne:
1 si todos los elementos del primer vector están en el segundo
2 si todos los elementos del segundo vector están en el primero
0 en caso contrario*/
#include <stdio.h>
int contiene(int vec1[], int vec2[], int dimVec1, int dimVec2);
int main(void) {
    int vec1[] = {1, 1, 5, 5, 9, 1};
    int vec2[] = {5, 9, 3, 1};
    int dimVec1 = sizeof(vec1)/sizeof(vec1[0]);
    int dimVec2 = sizeof(vec2)/sizeof(vec2[0]);
    int inclusion = contiene(vec1, vec2, dimVec1, dimVec2);
    printf("%d \n", inclusion);
}

int contiene(int vec1[], int vec2[], int dimVec1, int dimVec2){
    if (dimVec1 >= dimVec2){
        int contador = 0;

        for (int i = 0; i < dimVec2; i++){
            for (int j = 0; j < dimVec1; j++){
                if (vec1[j] == vec2[i]){
                    contador++;
                    break;
                }
            }
        }
        if (contador == dimVec2)
            return 2;
    }

    if (dimVec2 >= dimVec1){
        int contador = 0;

        for (int i = 0; i < dimVec1; i++){
            for (int j = 0; j < dimVec2; j++){
                if (vec1[i] == vec2[j]){
                    contador++;
                    break;
                }
            }
        }
        if (contador == dimVec1)
            return 1;
    }
    
    return 0;
    
}
//este codigo no funciona para determinados conjuntos donde hay elementos repetidos. Preguntar!!!


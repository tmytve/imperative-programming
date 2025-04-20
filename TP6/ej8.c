//Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada pueden tener elementos repetidos, pero el de salida NO debe tener repeticiones. 
#include <stdio.h>
#define DIM 10
void unionConjuntos(int vec1[], int vec2[], int dim1, int dim2, int vecFinal[]);
int pertenece(int vec[], int n, int dim);
int main(void) {
    int v1[DIM] = {1, 2, 3, 9, 10, 23, -1};
    int v2[DIM] = {2, 2, 3, 4, 5, 6, 25, 30, -1};
    int vecFinal[2 * DIM];
    unionConjuntos(v1, v2, DIM, DIM,vecFinal);
    for (int i = 0; vecFinal[i] != -1; i++){
        printf("%d  ", vecFinal[i]);
    }
    printf("-1\n");
    

}



void unionConjuntos(int vec1[], int vec2[], int dim1, int dim2, int vecFinal[]){
    int i = 0, j = 0, k = 0;
    while (vec1[i] != -1 && vec2[j] != -1){
        if (vec1[i] < vec2[j]){
            if (!pertenece(vecFinal, vec1[i], k)){
                vecFinal[k++] = vec1[i];
            }
            i++;
        } else if (vec1[i] > vec2[j]){
            if (!pertenece(vecFinal, vec2[j], k)){
                vecFinal[k++] = vec2[j++];
            }
            j++;
        } else { 
            if (!pertenece(vecFinal, vec1[i], k)){
                vecFinal[k++] = vec1[i];
            }
            i++;
            j++;
        }
    }
    while (vec1[i] != -1) {
        if (!pertenece(vecFinal, vec1[i], k)) {
             vecFinal[k++] = vec1[i];
        }
        i++;
    }
    // Copiar lo que reste de vec2
    while (vec2[j] != -1) {
        if (!pertenece(vecFinal, vec2[j], k)) {
             vecFinal[k++] = vec2[j];
        }
        j++;
    }
    // Terminar el vector resultante con -1
    vecFinal[k] = -1;
}

int pertenece(int vec[], int n, int dim){
    for (int i = 0; i < dim; i++){
        if (vec[i] == n){
            return 1;
        }
    }
    return 0;
}
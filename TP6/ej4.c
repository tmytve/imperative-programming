//Escribir una función que reciba un vector desordenado de números enteros y su dimensión, y construya otro vector eliminando los valores repetidos. La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada  no debe superar las 10 líneas).
#include <stdio.h>
#define DIM 10
int estaRepetido(const int arr[], int elem, int dim);
int eliminaRepetidos(int vec[], int dim, int resp[]);
int main(void) {
    int vec[DIM] = {2, 4, 2, 5, 9, 5, 2, 1, 0, 11};
    int resp[DIM];
    printf("Dimension original = %d\n", DIM);
    int respuesta = eliminaRepetidos(vec, DIM, resp);
    printf("Nueva dimension = %d\n", respuesta);
}

int estaRepetido(const int arr[], int elem, int dim){
    for (int i = elem + 1; i < dim; i++){
        if (arr[elem] == arr[i]){
            return 1;
        }   
    }
    return 0;
}

int eliminaRepetidos(int arr[], int dim, int resp[]){
    int dimResp = 0;

    for (int i = 0; i < dim; i++){
        if (!estaRepetido(arr, i, dim)){
            resp[dimResp] = arr[i];
        }
    }

    return dimResp;
}
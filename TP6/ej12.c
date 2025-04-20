/*
Escribir una función que cambie una matriz cuadrada por su traspuesta, recibiendo sólo los siguientes 2 parámetros:
un número entero positivo que indique la dimensión de la matriz
la matriz cuadrada 

 	Dicha función debe hacer la conversión sobre la misma matriz recibida, sin usar vectores auxiliares.

La traspuesta de una matriz se obtiene cambiando  cada elemento Aij  por el elemento Aji.
*/

#include <stdio.h>
#define DIM 3
void printMatrix(int matrix[][DIM], int dimension);
void traspuesta(int matrix[][3], int dimesion);
int main(void) {
    int matrix[][DIM] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
        traspuesta(matrix, DIM);
        printMatrix(matrix, DIM);
}


void traspuesta(int matrix[][3], int dimesion){
    for (int i = 0; i < dimesion; i++){
        for (int j = i+1; j < dimesion; j++){
            int aux = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = aux;

        }
    }
}

void printMatrix(int matrix[][DIM], int dimension){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
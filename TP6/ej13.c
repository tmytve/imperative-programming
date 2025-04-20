//Escribir una función que realice el producto de dos matrices cuadradas y lo devuelva en una tercera. El algoritmo de la función que realiza el producto no debe tener más de dos ciclos for anidados explícitamente, pero sí puede utilizar funciones auxiliares que contengan ciclos (Ninguna de las funciones debe superar las 5 líneas)

#include <stdio.h>
#define DIM 3
void productoMatricial(int A[][DIM], int B[][DIM], int dimesion, int C[][DIM]);int calcularElemento(int A[][DIM], int B[][DIM], int fila, int col, int dim);
void printMatrix(int C[][DIM], int dim);
int main(void) {
    int A[][3] = {{1,2,3},
                  {4,5,6},
                  {7,8,9}};

    int B[][3] = {{1,2,3},
                  {4,5,6},
                  {7,8,9}};
    
    int C[DIM][DIM];
    productoMatricial(A, B, DIM, C);
    printMatrix(C, DIM);
}

void productoMatricial(int A[][DIM], int B[][DIM], int dimesion, int C[][DIM]){
    for (int i = 0; i < dimesion; i++){
        for (int j = 0; j < dimesion; j++){
            C[i][j] = calcularElemento(A, B, i, j, dimesion);
        }
        
    }
    
}

int calcularElemento(int A[][DIM], int B[][DIM], int fila, int col, int dim){
    int suma = 0;
    for (int i = 0; i < dim; i++){
        suma += A[fila][i] * B[i][col];
    }
    return suma;
}


void printMatrix(int C[][DIM], int dim){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

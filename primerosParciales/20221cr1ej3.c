/*
Escribir una función esMagica que reciba como único parámetro una matriz de enteros de N filas y N columnas y determine si es un “cuadrado mágico”.
Una matriz es cuadrado mágico cuando:
es cuadrada (NxN) (donde N es una constante simbólica)
tiene todos los números del 1 al N2
la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier columna
*/
#include <stdio.h>
#define N 4
int tienenTodosHastaNN(int matrix[N][N]);
int sumaElementos(int matrix[N][N]);
int esMagica(int matrix[N][N]);

int main(void) {
    int matrix[N][N] = {{16,3,2,13},{5,10,11,8},{9,6,7,12},{4,15,14,1}};
    //printf("La matriz %ses magica\n", esMagica(matrix)? "": "no ");
    printf("%d\n", esMagica(matrix));
}


int esMagica(int matrix[N][N]){
    return sumaElementos(matrix) && tienenTodosHastaNN(matrix);
}

int sumaElementos(int matrix[N][N]){
    int num = 0;
    for (int i = 0; i < N; i++){
        num += matrix[i][0];   
    }

    for (int i = 0; i < N; i++){
        int sumFila = 0;
        for (int j = 0; j < N; j++){
            sumFila += matrix[i][j];
        }
        if (sumFila != num){
                return 0;
        }
    }

    for (int j = 0; j < N; j++){
        int sumColumna = 0;
        for (int i = 0; i < N; i++){
            sumColumna += matrix[i][j];
        }
        if (sumColumna != num){
            return 0;
        }
    }
    
    return 1;
}




int tienenTodosHastaNN(int matrix[N][N]){
    int dim = N*N;
    int vec[dim];
    for (int i = 0; i < dim; i++){
        vec[i] = 0;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            vec[matrix[i][j] - 1]++;
        }
    }
    
    for (int i = 0; i < dim; i++){
        if (vec[i] != 1){
            return 0;
        }
    }
    return 1;
}
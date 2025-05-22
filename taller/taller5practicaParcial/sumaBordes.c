#include <stdio.h>
#define M 4
int main(void) {
    int m1[M][M] = {{1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};

}

int sumaBorde(int matrix[M][M], int b){
    int suma = 0;
    for (int i = 0; i < M - b - 1; i++){
        suma += matrix[b][i] + matrix[i][M - b -1];
        suma += matrix[M - b - 1][i + 1] + matrix[i + 1][b];
    }
    return suma;
}

void bordes(int matrix[M][M], int sumas[]){
    for (int i = 0; i < M/2; i++){
        sumas[i] = sumaBorde(matrix, i);
    }
}

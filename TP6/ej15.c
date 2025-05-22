/*
Una imagen bmp se almacena en un archivo como una matriz de píxeles.
Si la imagen es de escala de grises, cada píxel ocupa un solo byte. Así, si la imagen tiene 20x30 píxeles, ocupa 600 bytes donde un byte con el valor 0x00 corresponde al negro y un byte con el valor 0xFF corresponde al blanco. Cualquier valor entre 0x00 y 0xFF será una tonalidad de gris.
Realizar una función suavizar que, dada una imagen, la suavice aplicando un filtro de media de valor W, con W impar. Esto significa que cada píxel (i, j) de la nueva imagen se obtiene a partir de la media aritmética de los píxeles que se encuentran en la imagen original de la submatriz de tamaño WxW centrada en (i,j).
      La función suavizar recibe como únicos parámetros la matriz y W. Si W es menor que 3 o no es impar, la función no altera la imagen. 
El ancho y alto de la imagen son las constantes simbólicas ANCHO y ALTO respectivamente.
*/
#include <stdio.h>
#include <assert.h>
#define ALTO 6 //filas
#define ANCHO 5 //columnas
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

int promedio(int matrix[][ANCHO], int i, int j , int W);
void suavizar(int matrix[][ANCHO], int W);
void printMatrix(int matrix[][ANCHO], int filas, int columnas);
int main(void) {
    int W = 3;
    int matrix[ALTO][ANCHO] = {{10,10,20,23,24},
                               {10,12,8,25,23},
                               {12,14,18,26,22},
                               {12,14,19,20,22},
                               {13,16,19,20,22},
                               {14,14,19,21,23}};

    int newMatrix[ALTO][ANCHO];
    suavizar(matrix, W);
    printMatrix(matrix, ALTO, ANCHO);
}


void suavizar(int matrix[][ANCHO], int W){     
    if (W % 2 == 0 || W < 3)
        return;
    
    int matrixAux[ALTO][ANCHO];
    for (int i = 0; i < ALTO; i++){
        for (int j = 0; j < ANCHO; j++){
            matrixAux[i][j] = promedio(matrix, i, j, W);
        }   
    }
    
    for (int i = 0; i < ALTO; i++){
        for (int j = 0; j < ANCHO; j++){
            matrix[i][j] = matrixAux[i][j];
        }
    }
}

int promedio(int matrix[][ANCHO], int fil, int col , int W){
    int r = W/2;
    int sum = 0, cant = 0;
    for (int i = MAX(0, fil - r); i < MIN(ALTO-1, fil + r); i++){
        for (int j = MAX(0,col-r); j < MIN(ANCHO-1, col+r); j++){
            sum += matrix[i][j];
            cant++;
        }
    }
    return sum/cant;
}

void printMatrix(int matrix[][ANCHO], int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
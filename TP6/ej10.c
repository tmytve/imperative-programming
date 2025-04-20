/*
Los laboratorios de Propulsión por Reacción tienen la representación del cielo y sus estrellas, digitalizada en una matriz bidimensional de hasta 80 columnas por 20 filas. Cada elemento de la misma representa la cantidad de luz que hay en una zona del cielo con un rango de intensidad entre 0 y 20. En el lugar de coordenadas (i,j) del cielo se considera que hay una estrella si el elemento Aij correspondiente  cumple con la siguiente relación:
		( A[i,j] + suma de las ocho intensidades circundantes ) / 9 > 10    (hacer las cuentas como int)

	Escribir una función (en no más de 15 líneas) que reciba tres parámetros de entrada representando a una matriz de dichas características y sus dimensiones. Dicha función debe localizar gráficamente las estrellas en la pantalla representando las mismas con el carácter ‘*’. La función debe ignorar las aristas de la matriz. 

Para completar la matriz no hace falta interactuar con el usuario, se puede utilizar números aleatorios.
Para una correcta separación de front y back, necesitás hacer una función que genere la matriz (back-end) y otra que grafique el "cielo" en salida estándar (front-end).
*/
#include <stdio.h>
#include "random.h"
#define row 20
#define col 80
#define RELACION(matriz, i, j) (((matriz[i][j] + matriz[i][j+1] + matriz[i][j-1] + matriz[i+1][j] + matriz[i-1][j] + matriz[i+1][j+1] + matriz[i+1][j-1] + matriz[i-1][j+1] + matriz[i-1][j-1]) / 9) > 10)

void randomMatrix(int vec[][80], int fila, int columna);
void mostrarCielo(int matriz[][80], int i, int j);

int main(void) {
    int vec[row][col];
    randomMatrix(vec, row, col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", vec[i][j]);
        }   
        printf("\n");
    }
    printf("Cielo estrellado: \n");
    mostrarCielo(vec, row, col);
    return 0;
}

void randomMatrix(int vec[][80], int fila, int columna){
    randomize();
    randNormalize();
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            vec[i][j] = randInt(0, 20);
        }
    }
}

void mostrarCielo(int matriz[][80], int filas, int columnas){
    int sum = 0;
    for (int i = 0; i < filas-1; i++){
        for (int j = 0; j < columnas-1; j++){
            if (RELACION(matriz, i, j)){
                printf("* ");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}



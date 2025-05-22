/*
Escribir una función que reciba una matriz de números enteros y cuya cantidad de filas está dada por la constante simbólica FILS y la cantidad de columnas por la constante simbólica COLS.

Se asegura que ambas constantes son mayores o iguales a 2 (no hace falta validarlo)

La función debe retornar 1 si la matriz es "ascendente", -1 si es "descendente" y 0 si no es ascendente ni descendente. Se dice que una matriz es ascendente si recorriendola en forma ordenada por filas cada elemento es mayor o igual al anterior, En forma análoga se define una matriz descendente.
El recorrido comienza por el elemento [0][0], continúa con el [0][1] y luego de terminar la primera fila hace lo mismo con la segunda fila, tercer fila, etc.
*/

#include <stdio.h>
#define FILS 4
#define COLS 4
int ordenMatriz(int matrix[][COLS], int filas, int columnas);
int main(void) {
    int m1[][COLS] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}}; // m1 es ascendente
                
    int m2[][COLS] = {
		{19,13,12,8},
		{7,7,5,-1},
		{-6,-10,-14,-16},
        {-17,-18,-19,-20}
	}; // m2 es descendente

    int m3[][COLS] = {
		{-6,-5,-6,6},
		{7,9,10,14},
		{21,32,45,46},
        {21,32,45,46}
	}; // m3 no es ascendente ni descendente

    int m5[][COLS] = {
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	}; // m5 es ascendente y descendente. La función podría devolver 1 ó -1

    int resultado = ordenMatriz(m2, FILS, COLS);
    printf("%s \n", resultado == 1 ? "Ascendente" : "Descendente");
}



int ordenMatriz(int matrix[][COLS], int filas, int columnas){
    int esAscendente = 1;
    int esDescendente = 1;

    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){

            int nextI = i, nextJ = j+1;

            if (nextJ == columnas){ //si estoy al final de una fila paso a la siguiente
                nextJ = 0;
                nextI++;
            }
            
            if (nextI < filas){
                if (matrix[i][j] > matrix[nextI][nextJ]){
                    esAscendente = 0;
                }else{
                    esDescendente = 0;
                }
            }
        }
    }
    if(esAscendente) return 1;
    if(esDescendente) return -1;
    return 0;
}


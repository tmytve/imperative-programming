//Escribir una función que ordene las filas de una matriz de cualquier tamaño, según el valor de una determinada columna. La función recibirá como parámetros la matriz, la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación, teniendo en cuenta que la primera columna es la columna 1 (uno).
//Para ordenar se puede usar el bubble sort ( https://www.geeksforgeeks.org/bubble-sort/ ) o selection sort (https://www.geeksforgeeks.org/selection-sort/ )
#include <stdbool.h>
#include <stdio.h>
#define row 4
#define col 5
void swapRows(int matrix[][col], int fila1, int fila2, int columnas);
void ordenPorColumna(int matrix[][col], int filas, int columnas, int columnaOrden);

int main(){
    int matrix[row][col] = {{1,2,3,4,5}, 
                            {6,7,8,9,10},
                            {3,5,8,2,1}, 
                            {8,1,3,6,7}};


    ordenPorColumna(matrix, row, col, 2);

    for (int i = 0; i < row; i++){ //print matrix
        for (int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}

                //BubbleSort para matrices
void swapRows(int matrix[][col], int fila1, int fila2, int columnas){
    for (int j = 0; j < columnas; j++){
        int temp = matrix[fila1][j];
        matrix[fila1][j] = matrix[fila2][j];
        matrix[fila2][j] = temp;
    }
}
void ordenPorColumna(int matrix[][col], int filas, int columnas, int columnaOrden){
    int colIndex = columnaOrden - 1;
    for (int i = 0; i < filas-1; i++){
        for (int j = 0; j < filas - i - 1; j++){
            if (matrix[j][colIndex] > matrix[j+1][colIndex]){
                swapRows(matrix, j, j+1, columnas);
            }   
        }
    }
}



/*                                     BubbleSort Algorithm para Vectores
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int length){
    int i, j;
    bool swapped;
    for (i = 0; i < length - 1; i++) {
        swapped = false;
        for (j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
*/


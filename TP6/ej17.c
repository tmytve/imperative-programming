/*
Escribir una función armaFilas que recibe una matriz de enteros de N filas y M columnas, y un vector de dimensión N.
La función debe armar los números que se forman con cada fila y guardarlos en el vector.
Si hubiera números negativos o de más de una cifra en una fila, no se completa el armado de ese número, pero se sigue con la próxima fila.
La función retorna en su nombre la dimensión final del vector de números.
*/

#include <stdio.h>
#include <math.h> // -lm
#define N 4
#define M 4
#define esUnDigitoPositivo(dig) (dig >= 0 && dig < 10)

int armaFlias(int matrix[][M], int nfilas, int mColumnas, int vec[]);

int main(void) {
    int matrix[N][M] = {{1,3,2,5},
                        {5,12,1,8},
                        {9,6,7,2},
                        {4,52,4,1}};

    int vec[N];
    printf("%d \n", armaFlias(matrix, N, M, vec));

}

int armaFlias(int matrix[][M], int nfilas, int mColumnas, int vec[]){
    int vecAux[N];
    int indiceVecValido = 0;
    
    for (int i = 0; i < nfilas; i++){
        int num = 0;
        int filaValida = 1;

        for (int j = 0; j < mColumnas; j++){
            if (!esUnDigitoPositivo(matrix[i][j]) ){
                filaValida = 0;
                break;
            }
        }

        if (filaValida){
            for (int j = 0; j < mColumnas; j++){
                num += matrix[i][j] * pow(10, mColumnas - j - 1);
            }
            vec[indiceVecValido++] = num;
        }
        
    }

    
    return indiceVecValido;
}


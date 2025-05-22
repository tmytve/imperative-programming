/*Escribir una función que reciba dos matrices cuadradas de enteros, de dimensión DIM (DIM es una constante simbólica ya definida) y retorne:
1 si cada elemento de la fila n de la primera matriz está en la columna n de la segunda matriz, para todo n entre 0 y DIM-1
2 si cada elemento de la columna n de la primera matriz está en la fila n de la segunda matriz, para todo n entre 0 y DIM-1
En caso de cumplir ambas condiciones puede retornar 1 ó 2
0 si no se cumple ninguna de las dos condiciones

Las matrices pueden tener elementos repetidos y no hay ningún tipo de orden,
*/

#include <stdio.h>
#define DIM 4
int ejercicio(int m1[DIM][DIM], int m2[DIM][DIM]);
int filaM1AColumnaM2(int m1[DIM][DIM], int m2[DIM][DIM]);
int ColumnaM1AFilaM2(int m1[DIM][DIM], int m2[DIM][DIM]);
int esSubconjunto(int vec1[], int vec2[]);
int pertenece(int vec[], int x);

int main(void) {
    int m1[DIM][DIM] = {{1,3,1,2},
                        {5,5,6,6},
                        {2,3,4,5},
                        {1,1,1,2}};

    int m2[DIM][DIM] = {{1,6,5,2},
                        {2,6,3,2},
                        {3,6,2,1},
                        {3,5,4,1}};

    int m3[DIM][DIM] = {{1,3,1,2},
                        {5,5,6,6},
                        {2,3,4,5},
                        {1,1,1,2}};
    
    int m4[DIM][DIM] = {{1,2,5,2},
                        {1,3,3,5},
                        {1,4,4,6},
                        {2,5,6,6}};
                        

    printf("%d \n", ejercicio(m1,m2));
    printf("%d \n", ejercicio(m3,m4));

}

int ejercicio(int A[DIM][DIM], int B[DIM][DIM]){
    if ((filaM1AColumnaM2(A, B)) || (filaM1AColumnaM2(A, B) && ColumnaM1AFilaM2(A,B)))
        return 1;
    
    if (ColumnaM1AFilaM2(A,B))
        return 2;
    

    return 0;
}


int filaM1AColumnaM2(int m1[DIM][DIM], int m2[DIM][DIM]){
    for (int n = 0; n < DIM; n++){
        int vec[DIM];
        for (int i = 0; i < DIM; i++){
            vec[i] = m2[i][n];
        }
        if (!esSubconjunto(m1[n], vec)){
            return 0;
        }
    }
    return 1;
}

int ColumnaM1AFilaM2(int m1[DIM][DIM], int m2[DIM][DIM]){
    for (int n = 0; n < DIM; n++){
        int vec[DIM];
        for (int i = 0; i < DIM; i++){
            vec[i] = m1[i][n];
        }
        if (!esSubconjunto(vec, m2[n])){
            return 0;
        }
    }
    return 2;
}

int esSubconjunto(int vec1[], int vec2[]){ // 1 esta incluido en 2
    for (int i = 0; i < DIM; i++){
        if (!pertenece(vec2, vec1[i])){
            return 0;
        }
    }
    return 1;
}


int pertenece(int vec[], int x){
    for (int i = 0; i < DIM; i++){
        if (vec[i] == x){
            return 1;
        }
    }
    return 0;
}
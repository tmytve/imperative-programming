#include <stdio.h>
#include <assert.h>

#define DIM 9
#define digitoValido(n) (((n) >= 1) && ((n) <= 9))

int sudokuSolver(int m[][DIM]);
int cumpleFila(int vec[]);
int cumplePorFilas(int matrix[][DIM]);
int cumplePorColumnas(int matrix[][DIM]);
int cumplePorSubmatices(int matrix[][DIM]);

int main(void) {

  // Una matriz vacía no es solución
  //int sudoku[DIM][DIM] = {{0}};

  //assert(sudokuSolver(sudoku)==0);

  int sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };
  assert(sudokuSolver(sudoku2)==1);
  
  int sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  int sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };
    
  assert(sudokuSolver(sudoku4)==0);

  int sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);


  puts("Ok!");
  return 0;
}


int sudokuSolver(int matrix[][DIM]){
    return cumplePorFilas(matrix) && cumplePorColumnas(matrix) && cumplePorSubmatices(matrix);
}


int cumplePorSubmatices(int matrix[][DIM]){
    int dimSubMatrix = 3;
    int vec[DIM];
    //recorro cada submatriz de 3x3
    for (int bi = 0; bi < DIM; bi+=dimSubMatrix){
        for (int bj = 0; bj < DIM; bj+=dimSubMatrix){
            //reinicio el vector
            int k = 0;

            for (int i = 0; i < dimSubMatrix; i++){
                for (int j = 0; j < dimSubMatrix; j++){
                    int v = matrix[bi + i][bj + j];
                    if (!digitoValido(v))
                        return 0;
                    vec[k++] = v;
                }
            }
            
            if(!cumpleFila(vec))
                return 0;

        }
    }
    return 1;
}




int cumplePorColumnas(int matrix[][DIM]){
    int vec[DIM], counter = 0;
    for (int j = 0; j < DIM; j++){ 
        for (int i = 0; i < DIM; i++){
            vec[i] = matrix[i][j];
        }
        if (cumpleFila(vec)){
            counter++;
        }
    }
    return counter == DIM;
}

int cumplePorFilas(int matrix[][DIM]){
    int counter = 0;
    for (int i = 0; i < DIM; i++){
        if (cumpleFila(matrix[i])){
            counter++;
        }
    }
    return counter == DIM;
}


int cumpleFila(int vec[]){ //algoritmo para chequear repeticion O(1)
    int vecAux[DIM] = {0};
    //Dentro de un vector auxiliar con todos ceros, voy sumando uno a cada indice a medida que recorro el vector original. todos los elementos del vecAuxiliar deberian quedar en 1 si no hay repetidos, si algun elemento del vecAux > 1  --> hay un repetido
    for (int i = 0; i < DIM; i++){
        if (digitoValido(vec[i])){
            vecAux[vec[i] - 1]++;   
        }else{
            return 0;
        }
    }
    
    for (int i = 0; i < DIM; i++){
        if (vecAux[i] > 1){
            return 0;
        }
    }
    
    return 1;   
}


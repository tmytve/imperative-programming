// MATRICES
//El siguiente programa asigna valores al azar a todos los elementos de la matriz numbers. 
#define ROWS    10
#define COLS    5
#include <stdio.h>
#include "random.h"
int main(void){
    int numbers[ROWS][COLS] ;
    randomize();
    randNormalize();
    int k, j;
    for (int i = 0; i < ROWS; i++){
       for (j = 0; j < COLS; j++){
        numbers[i][j] = randInt(0,100);
        printf("%d\t", numbers[i][j]);
       }
       putchar('\n');
    }
    return 0;
}

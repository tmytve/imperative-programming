#include <stdio.h>
#include <assert.h>
int esEspejo(int vec1[], int vec2[], int dimVec);
int pertenece(int vec[], int dimVec, int x);
int matricesEspejo(int fil, int col, int m1[][col], int m2[][col]/*aclaracion*/);
#define COLS 4
int main(void) {
    int m1[][COLS] = {{5, 3, 4, 3},// elementos 3, 4 y 5
                      {1, 2, 1, 1},// elementos 1 y 2
                      {6, 7, 8, 9} // elemtntos 6, 7, 8 y 9
    };

    int m2[][COLS] = {{3, 4, 3, 5},// elementos 3, 4 y 5
                      {1, 1, 2, 1},// elementos 1 y 2
                      {9, 8, 7, 6} // elementos 6, 7, 8 y 9
    };

    assert(matricesEspejo(3, 4, m1, m2) == 1);

    int m3[][3] = {{5, 3, 4}, // elementos 3 y 5 (*)
                   {5, 4, 3}, // elementos 3, 4 y 5
                   {6, 7, 9} // elementos 6, 7 y 9
    };

    int m4[][3] = {{3, 5, 3},// elementos 3, 4 y 5 (*)
                   {4, 3, 5},// elementos 3, 4 y 5
                   {6, 9, 7} // elementos 6, 7 y 9
    };

    assert(!matricesEspejo(3, 3, m3, m4));
    //printf("%d\n ", matricesEspejo(3, 3, m3, m4));
    puts("OK!");
    return 0;
}



int matricesEspejo(int fil, int col, int m1[][col], int m2[][col]/*aclaracion*/){
    for(int i = 0; i < fil; i++){
        if(!esEspejo(m1[i], m2[i], col) || !esEspejo(m2[i], m1[i], col)){ //|| !esEspejo(m2[i], m1[i], col lo que me falto el en parcial
            return 0;
        }
    }
    return 1;
}
 
int esEspejo(int vec1[], int vec2[], int dimVec){
    for(int i = 0; i < dimVec; i++){
        if(!pertenece(vec1, dimVec, vec2[i])){ 
            return 0;
        }
    }
    return 1;
}
 
int pertenece(int vec[], int dimVec, int x){
    for(int i = 0; i < dimVec; i++){
        if(vec[i] == x){
            return 1;
        }
    }
    return 0;
}

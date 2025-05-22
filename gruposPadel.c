#include <stdio.h>
#include "random.h"
#define DIM 8
void desordena(char *vec[], int dim);
void printArray(char *arr[], int dim);

int main(void) {
    char *vec[DIM] = {"tito","gonza","facu","juani","arce","rafa","luquitas","manu"};
    desordena(vec, DIM);
    printArray(vec, DIM);
    printf("\n");

}

void desordena(char *vec[], int dim){
    randomize();
    randNormalize();
    for (int i = 0; i < dim; i++){
        int r = randInt(0, dim);
        char *temp = vec[i];
        vec[i] = vec[r];
        vec[r] = temp;
    }
    
}

void printArray(char *arr[], int dim){
    int equipo = 1;
    for (int i = 0; i < dim; i++){
        if (i % 2 == 0){
            printf("Equipo %d:\n", equipo++);
        }
        
        printf("%s\n",arr[i]);
    }
    
}
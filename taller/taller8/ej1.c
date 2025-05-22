//Completar para que los tres códigos sean iguales (generen un arreglo de 10 posiciones en 0)
#include <stdio.h>
#include <stdlib.h>
int * arr;
#define TAM 10

void mostrarArreglo(int *arr, int tam) {
    for(int i = 0; i < tam; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//1. malloc + inicializacion manual
int i;
arr = malloc(TAM*sizeof (arr[0]));
for (int i = 0; i < TAM; i++){
    arr[i] = 0;
}
mostrarArreglo(arr,TAM);
free(arr);

//2. 
arr = NULL; //para usar el realloc
arr = realloc(arr, TAM * sizeof(arr[0]));
for (int i = 0; i < TAM; i++){
    arr[i] = 0;
}
free(arr);

//3. calloc ya inicializa en 0
arr = calloc(TAM, sizeof(arr[0])); //  calloc(cantidad, tamaño)
free(arr);


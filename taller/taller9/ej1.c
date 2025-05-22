/*Implementar una función que reciba un arreglo de nombres de alumnos, el
arreglo de notas y retorne la lista de aprobados.*/

#define NOTA_APROBADO 6
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]){
    
    int k = 0;
    for (int i = 0; i < tam; i++){
        if (notas[i] >= NOTA_APROBADO){
            aprobados[k] = malloc(strlen(arrNombres[i]) + 1);
            strcpy(aprobados[k++], arrNombres[i]);
        }
    }
    return k;
}

//libero la memoria por cada malloc que hice
static void liberarAprobados(char *aprobados[], size_t n){
    for (int i = 0; i < n; i++)
        free(aprobados[i]);
}

static void mostrarNombres(char *arrNombres[], size_t n){
    for (int i = 0; i < n; i++)
        printf(" %s\n", arrNombres[i]);
}



int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]);
static void mostrarNombres(char *arrNombres[], size_t n);
int main(void) {
    char *arrNombres[] = {"anita", "pepe", "fabi", "carlos", "tere"};
    char *aprobados[5];
    int notas[] = {3, 4, 8, 10, 1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char *);
    mostrarNombres(arrNombres, tam);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
    printf("\nAprobados:\n");
    mostrarNombres(aprobados, tamApro);
    return 0;
}


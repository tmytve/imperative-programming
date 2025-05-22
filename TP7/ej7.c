/*Rehacer el problema del ejercicio anterior, pero considerando que la cantidad X de dígitos sea elegida por el usuario. ¿Cambia el árbol de módulos? ¿Cambia la tabla de interfaces?*/
#include <stdio.h>
#include "random.h"
#include "getnum.h"
#include <math.h>
#define cantDigitosUnaCifra 9
int pertenece(int vec[], int dim, int x);
int hayRepetidos(int num, int x);
int * generaAleatorio(unsigned x);
int elegirNivel(void);
int * leerNumero(int x);
int hayRepetidos(int num, int x);
int cantidadBien(int generado[], int input[], int x);
int cantidadRegular(int generado[], int input[], int x);
int coincideNumero(int *pG, int *pI, int x);

int main(void) {
    int X;
    do{
        X = getint("Elija la cantidad de digitos del numero (max 9): ");
    } while (X < 1 || X > 9);
    
    int *pG = generaAleatorio(X);
    printf("Numero generado: ");
    for (int i = 0; i < X; i++){
        printf("%d", pG[i]);
    }
    printf("\n");
    int nivel = elegirNivel();
    
    while (nivel > 0) {
        printf("Intentos restantes: %d\n", nivel);
        int *pI = leerNumero(X);

        int bien = cantidadBien(pG, pI, X);
        int regular = cantidadRegular(pG, pI, X);

        printf("Bien: %d, Regular: %d\n", bien, regular);

        if (bien == X) {
            printf("GANASTE EL JUEGO\n");
            free(pI);
            break;
        }

        free(pI);
        --nivel;
    }
    if (nivel == 0) {
        printf("PERDISTE\n");
    }
    free(pG);
    return 0;
    
}

int * generaAleatorio(unsigned x){
    randomize();
    randNormalize();
    int *vec = malloc(x*sizeof(vec[0]));
    for (int i = 0; i < x; i++)
        vec[i] = 0; //inicializo el vector en ceros
    
    for (int i = 0; i < x; i++){
        int numero;
        do{
            numero = randInt(1, 9);
        } while (pertenece(vec, i, numero)); //busco entre los elementos ya agregados si el numero q voy a agregar ya esta en el arreglo
        vec[i] = numero;
    }
    return vec;
}

int pertenece(int vec[], int dim, int x){
    for (int i = 0; i < dim; i++){
        if (vec[i] == x){
            return 1;
        }
    }
    return 0;
}

int elegirNivel(void){
    int n;
    do{
        n = getint("Ingrese el nivel de dificultad (intentos): ");
    } while (n < 1);
    return n;
}

int * leerNumero(int x){
    int *vec = malloc(x*sizeof(vec[0]));
    int num;
    do {
    num = getint("Escriba un numero de %d cifras distintas: ", x);
    
    } while ((num < (int)pow(10, x-1) || num >= (int)pow(10, x)) || hayRepetidos(num, x));
    
    for (int i = x-1 ; i >= 0; i--){
        vec[i] = num%10;
        num /= 10;
    } //cada elemento del vector va a ser una cifra del numero
    
    return vec;
}

int hayRepetidos(int num, int x){
    //lleno vec con los digitos de num
    int vec[x];
    for (int i = 0; i < x; i++){
        int aux = num%10;
        num /= 10;
        vec[i] = aux;
    }
    int *vecAux = malloc(9*sizeof(int)); //reservo una posision para cada digito posible (1 al 9)
    for (int i = 0; i < cantDigitosUnaCifra; i++)
        vecAux[i] = 0; // lleno un vector auxiliar con ceros (cada posision pertenece a un digito)
    
    for (int i = 0; i < x; i++)
        vecAux[vec[i] - 1]++; //cuento la cantidad de cada digito que hay

    for (int i = 0; i < cantDigitosUnaCifra; i++){
        if (vecAux[i] > 1){ //si la cantidad de alguno es mayor a uno es que hay repetidos
            free(vecAux);
            return 1;
        } 
    }
    free(vecAux);
    return 0; //sino retorno que no hay repetidos
}

int cantidadBien(int generado[], int input[], int x){
    int cantBien = 0;
    for (int i = 0; i < x; i++){
        if (generado[i] == input[i])
            cantBien++;
    }

    if (cantBien == x){
        return x;
    }else{
        return cantBien;
    }
    return 0;    
}

int cantidadRegular(int generado[], int input[], int x){
    int cantRegular = 0;
    for (int i = 0; i < x; i++){
        if (pertenece(generado, x, input[i]) && (generado[i] != input[i])){
            cantRegular++;
        }
    }
    return cantRegular;
}

int coincideNumero(int *pG, int *pI, int x){
    int cantRegular = cantidadRegular(pG, pI, x);
    int cantBien = cantidadBien(pG, pI, x);

    if (cantBien == x){
        return 1; //ambos arreglos son exactamente iguales
    }else{
        printf("Cantidad bien = %d\n", cantBien);
        printf("Cantidad regular = %d\n", cantRegular);
        return 0;
    }
}
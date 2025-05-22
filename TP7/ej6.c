/*Escribir un programa para desarrollar el juego Mastermind descrito por las siguientes reglas:  

La computadora construye un conjunto aleatorio de X dígitos distintos (para X usar una constante simbólica). Sólo se usan los dígitos del 1 al 9
Se le  pide ingresar al usuario el nivel en que quiere jugar. Según esto se trabajará con una tolerancia de hasta N pasos, dentro de los cuales si no logra ganar el juego se termina automáticamente. 
El jugador entra un conjunto de X dígitos distintos por teclado. 
Si el número propuesto por el jugador coincide con el que generó la máquina o la cantidad de chances excedió el número tope N , el juego finaliza; sino el programa debe informarle cuántos dígitos están BIEN (son correctos y están en su lugar) y cuántos son REGULARES (son correctos pero están fuera de lugar) y se vuelve a ejecutar el paso anterior. Así se va guiando al jugador hasta que adivine el número.
*/
#include <stdio.h>
#include "random.h"
#include "getnum.h"
#include <math.h>
#define X 5
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
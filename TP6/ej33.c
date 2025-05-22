/*Existe un método para encriptar mensajes que consiste en mezclar las letras de un alfabeto y reemplazar cada letra del mensaje por la nueva letra que ocupa su lugar en el alfabeto.
	Se pide escribir tres funciones:
crearAlfabeto: recibe como parámetro de salida un vector de caracteres y lo completa con el alfabeto mezclado (letras 'A' a 'Z'). El alfabeto mezclado debe armarse utilizando un ciclo for.
codificar: que recibe dos parámetros de entrada que representan un mensaje a codificar y un alfabeto, y un parámetro de salida en el cual se devuelve el mensaje codificado.
decodificar: recibe dos parámetros de entrada que representan un mensaje a decodificar y un alfabeto, y un parámetro de salida en el cual se devuelve el mensaje decodificado.*/

#include <stdio.h>
#include "random.h"
#include <ctype.h>
#include <string.h>
#define TAM_ALFABETO 26
#define DIM_MAX 50
void crearAlfabeto(char alf[]);
void codificar(char sIN[], char alf[], char sOUT[]);


int main(void) {
    char alphOriginal[TAM_ALFABETO];
    for (int i = 0; i < TAM_ALFABETO; i++){ //lleno con 'A' a 'Z'
        alphOriginal[i] = 'A' + i;
    }
    printf("Alfabeto original: \n");
    for (int i = 0; i < TAM_ALFABETO; i++){
        printf("%c ", alphOriginal[i]);
    }

    printf("\nAlfabeto mezclado: \n");
    crearAlfabeto(alphOriginal);
    for (int i = 0; i < TAM_ALFABETO; i++){
        printf("%c ", alphOriginal[i]);
    }
    printf("\n");

    char sIN[DIM_MAX];
    char sOUT[DIM_MAX];
    strcpy(sIN, "thomas");
    codificar(sIN, alphOriginal, sOUT);
    printf("%s", sOUT);
    
    return 0;
}

void codificar(char sIN[], char alf[], char sOUT[]){
    char aux[TAM_ALFABETO + 1];
    for (int i = 0; i < TAM_ALFABETO; i++){
        aux[i] = 'A' + i; // alfabeto original
    }
    aux[TAM_ALFABETO] = '\0';
    int i;
    for (i = 0; sIN[i] != '\0'; i++){
        char c = toupper(sIN[i]);
        char *p = strchr(aux, c);
        if (p){
            int idx = p - aux;
            sOUT[i] = alf[idx];
        } else {
            sOUT[i] = sIN[i];
        }
        
    }
    sOUT[i] = '\0';
}

void descodificar(char sIN[], char alf[], char sOUT[]){
    
}



void crearAlfabeto(char alf[]){
    randNormalize();
    randomize();
    
    
    for (int i = 0; i < TAM_ALFABETO; i++){
        int j = randInt(0,i);
        char aux = alf[i];
        alf[i] = alf[j];
        alf[j] = aux;
    }
    
}

/*Escribir un programa interactivo para jugar al juego del ahorcado. Las palabras que almacena la máquina deben estar guardadas en un arreglo de strings constantes y cada vez que se elija jugar, utilizar aleatoriamente alguna de dichas palabras.
Antes de escribir el programa, realizar el diseño y la modularización, documentando cada módulo interviniente, tal como se mostró en los ejercicios 8 y 10.*/

#define cantPalabras 3
#include <stdio.h>
#include <string.h>
#include "getnum.h"
#include "random.h"
#include "ctype.h"

char *elijePalabra(char *palabras[]);
void jugar(char *palabra, int cantLetras);
int pertenece(char *palabra, char c);
int cantLetrasDistintas(char *palabra);

int main(void){
    char *palabras[] = {"codigo", "argentina", "matematica", "juego", "funcion", "mapa", "cuadrado"};
    char *elegida = elijePalabra(palabras);
    int cantLetras = strlen(elegida);

    // reservo memoria para la palabra a jugar
    char *palabra = malloc((cantLetras + 1) * sizeof(char));

    strcpy(palabra, elegida);
    
    //printf("DEBUG: Palabra elegida = %s\n", palabra);

    jugar(palabra, cantLetras);

    free(palabra);
    return 0;
}

char *elijePalabra(char *palabras[])
{
    randomize();
    randNormalize();
    int randIndx = randInt(0, cantPalabras - 1);
    return palabras[randIndx];
}

void jugar(char *palabra, int cantLetras){
    int intentos = getint("Elija la dificultad (intentos): ");
    int cantidadLetrasDistintas = cantLetrasDistintas(palabra);
    int contador = 0, k = 0;
    char letra;
    char aux[cantidadLetrasDistintas+1];


    while (intentos > 0 && cantidadLetrasDistintas != contador){
        //imprime el estado de la palabra
        printf("Palabra: ");
        for (int i = 0; i < cantLetras; i++) {
            if (pertenece(aux, palabra[i]))
                printf("%c ", palabra[i]);
            else
                printf("_ ");
        }
        printf("\n");

        //pide al usuario una letra
        scanf(" %c", &letra);
        for (int i = 0; i < cantLetras; i++)
            if ((palabra[i] == letra) && !pertenece(aux, letra)){
                aux[k++] = letra;
                contador++;
            }else{
                intentos--;
            }
        

        if (cantidadLetrasDistintas == contador){
            printf("Ganaste! 🏆 La palabra es: ");
            for (int i = 0; palabra[i] != '\0'; i++)
                putchar(toupper((unsigned char)palabra[i]));
            printf("\n");
        }

        printf("Intentos restantes: %d\n", intentos);
    }
    if (intentos == 0){
        printf("Perdiste ❌ La palabra era: ");
            for (int i = 0; palabra[i] != '\0'; i++)
                putchar(toupper((unsigned char)palabra[i]));
            printf("\n");
    }
}

int cantLetrasDistintas(char *palabra){
    int letras[26] = {0};
    int counter = 0;
    for (int i = 0; palabra[i] != '\0'; i++){
        int idx = palabra[i] - 'a';
        if (letras[idx] == 0){
            letras[idx] = 1;
            counter++;
        }
    }
    return counter;
}

int pertenece(char *palabra, char c){
    for (int i = 0; palabra[i] != '\0'; i++){
        if (palabra[i] == c)
            return 1;
    }
    return 0;
}


/*Se desea escribir una función para resolver una sopa de letras. Una sopa de letras se representa como una matriz de char de FILS filas y COLS columnas, donde FILS y COLS son constantes previamente definidas.
Se cuenta además con un vector ordenado que contiene las palabras a buscar, donde cada elemento es un string constante, y como marca de final contiene el string vacío.
Se cuenta además con las siguientes declaraciones de tipos

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

struct posicion {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
};

Se pide escribir la función resolverSopa que reciba:
una matriz de char de FILS x COLS que representa la sopa de letras
un diccionario ordenado alfabéticamente (vector de strings constantes donde el último elemento es un string vacío)
y retorne un vector de tipo struct posicion que contenga las palabras del diccionario que se encontraron en la sopa de letras, considerando que las palabras pueden estar en forma horizontal (hacia la izquierda o la derecha), vertical (hacia abajo o hacia arriba) o diagonal; y donde el último elemento del vector está representado por el valor NULL en el campo palabra.
El vector de respuesta debe ocupar la menor cantidad de memoria posible.
Si la palabra aparece más de una vez en la sopa, la respuesta debe contener todas las apariciones. 
En caso de error la función debe liberar la memoria reservada y retornar NULL.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILS 6
#define COLS 7
typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

typedef struct {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
}Posision;
Posision *resolverSopa(char sopa[FILS][COLS], char *diccionario[], int *cantRes);
int main(void) {
    char *diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
    char sopa[FILS][COLS] = {
        {'X','X','X','O','X','X','X'},
        {'A','P','A','C','Y','Y','O'},
        {'Z','E','Z','R','C','C','X'},
        {'E','R','R','O','R','X','X'},
        {'X','R','I','O','I','E','X'},
        {'X','O','X','X','O','X','X'}
    };

    int cantidad;
    Posision *respuestas = resolverSopa(sopa, diccionario, &cantidad);

    if (!respuestas) {
        printf("Error de memoria o no se encontraron palabras.\n");
        return 1;
    }

    for (int i = 0; respuestas[i].palabra != NULL; i++) {
        printf("Palabra: %s, Fila: %zu, Columna: %zu, Direccion: %d\n",
               respuestas[i].palabra, respuestas[i].fila, respuestas[i].columna, respuestas[i].direccion);
        free(respuestas[i].palabra); // Libera cada string copiado
    }
    free(respuestas); // Libera el vector de respuestas

    return 0;
}

Posision *resolverSopa(char sopa[FILS][COLS], char *diccionario[], int *cantRes){
    int capacidad = 4; // Capacidad inicial 
    int cantidad = 0;
    Posision *respuestas = malloc(capacidad * sizeof(Posision));

    for (int w = 0; diccionario[w][0] != '\0'; w++){
        char *palabra = diccionario[w];
        int len = strlen(palabra);

        for (int i = 0; i < FILS; i++){
        for (int j = 0; i < COLS; i++){
            for (Tdireccion dir = DER; dir <= D_AB; dir++){
                int found = 1;
                for (int k = 0; k < len; k++){
                    int ni = i, nj = j;
                    switch(dir){
                        case DER: nj = j + k; break;
                        case IZQ: nj = j - k; break;
                        case ABA: ni = i + k; break;
                        case ARR: ni = i - k; break;
                        case I_AR:  ni = i - k; nj = j - k; break;
                        case I_AB:  ni = i + k; nj = j - k; break;
                        case D_AR:  ni = i - k; nj = j + k; break;
                        case D_AB:  ni = i + k; nj = j + k; break;
                }
                if (ni < 0 || ni >= FILS || nj < 0 || nj >= COLS || sopa[ni][nj] != palabra[k]){
                    found = 0;
                    break;
                }
            }
            if (found){
                if (cantidad == capacidad){
                    capacidad *= 2;
                    respuestas = realloc(respuestas, capacidad * sizeof(Posision));
                }
                respuestas[cantidad].palabra = malloc(strlen(palabra)+1);
                strcpy(respuestas[cantidad].palabra, palabra);
                respuestas[cantidad].fila = i;
                respuestas[cantidad].columna = j;
                respuestas[cantidad].direccion = dir;
                cantidad++;
            }
            
        }
        // Redimensiona al tamaño justo
        respuestas = realloc(respuestas, cantidad * sizeof(Posision));
        *cantRes = cantidad;
        return respuestas;
        }
        }
    
    }
}


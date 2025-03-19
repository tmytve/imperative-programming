/*
Leer un carácter desde la entrada estándar e imprimir en la salida estándar si el mismo es una letra  o no. Considerar que el conjunto de caracteres es el del lenguaje inglés, o sea ignorar la ñ  y vocales acentuadas. Usar el operador condicional.
*/

#include <stdio.h>

int main(void) {
    int caracter = getchar();
    int esLetra = ((caracter>='A' && caracter<='Z') || (caracter>='a' && caracter<='z')); 
    esLetra ? printf("El caracter '%c' es una letra\n", caracter) : printf("El caracter '%c' NO es una letra\n", caracter); 
}

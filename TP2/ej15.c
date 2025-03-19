/*
Leer un carácter e imprimirlo en mayúscula. Considerar que el conjunto de caracteres es el del lenguaje inglés, o sea ignorar la ñ  y vocales acentuadas. (Usar operador condicional).
*/

#include <stdio.h>
#include <ctype.h>


int main(void) {
    unsigned char letra; 
    letra = getchar();
    printf("Caracter en original: %c\nCaracter en mayuscula: %c\n", letra, letra - ('a'-'A'));

    //Otra forma:
    printf("-------------------------------------\n");
    printf("Caracter en original: %c\nCaracter en mayuscula: %c\n", letra, toupper(letra));
}

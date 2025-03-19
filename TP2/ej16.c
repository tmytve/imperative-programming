/*
Leer dos caracteres seguidos de la entrada estándar e imprimir en la salida estándar si son iguales, si el primero es mayor o si el primero es menor, utilizando operadores condicionales:
a)  desde teclado, hacia pantalla
b)  redireccionando la entrada desde archivo, hacia pantalla
c)  desde teclado, redireccionando la salida a  un archivo
d)  redireccionando la entrada y la salida con archivos
*/

#include <stdio.h>

int main(void) {
    char letra1, letra2;
    printf("Ingrese el primer caracter: ");
    letra1 = getchar();
    getchar(); // Leer el salto de línea o espacio después del primer carácter

    printf("Ingrese el segundo caracter: ");
    letra2 = getchar();

    (letra1 == letra2)? printf("Los caracteres ingresados son igualesn\n"):
    (letra1>letra2)?printf("%c es mayor que %c\n", letra1, letra2):
                    printf("%c es mayor que %c\n", letra2, letra1);
    
}

// preguntar como hacer el b) c) d) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


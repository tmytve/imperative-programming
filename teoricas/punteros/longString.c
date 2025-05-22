//Utilizando aritmética de punteros, escribir la función longString que recibe como parámetro un string (arreglo de chars null-terminated) y retorna la cantidad de caracteres del mismo.

#include <stdio.h>
int longString(const char *string);
int main(void) {
    char * s = "Hola Mundo";
    printf("# de caracteres = %d\n", longString(s));
}

int longString(const char *string){
    int cantidad = 0;
    while (*string++){
        cantidad++;
    }
    return cantidad;
}











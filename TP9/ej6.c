/*Escribir una función que reciba como parámetro de entrada un string y retorne 1 si el mismo es palíndromo y 0 en caso contrario. Resolver el problema en forma recursiva*/
#include <string.h>
int esPalindromo(char *str, int inicio, int fin){
    //caso base: 
    if(inicio >= fin) return 1;
    if (str[inicio] != str[fin]) return 0;
    //paso recursivo:
    return esPalindromo(str, inicio + 1, fin - 1);
}

#include <stdio.h>

int main(void) {
    char str[100];
    printf("Ingrese una cadena: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Elimina el salto de línea

    int len = strlen(str);
    if (esPalindromo(str, 0, len - 1))
        printf("La cadena es palíndromo\n");
    else
        printf("La cadena no es palíndromo\n");
}

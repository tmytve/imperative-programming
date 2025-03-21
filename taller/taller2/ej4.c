#include <stdio.h>

int main(void) {
    int c;
    int foundDot = 0;  // indica si ya se encontró el punto decimal
    int sum = 0;       // suma de los dígitos decimales

    printf("Ingrese un número con parte decimal: ");
    
    // Se lee caracter a caracter hasta fin de línea o fin de archivo.
    while ((c = getchar()) != '\n' && c != EOF) {
        if (!foundDot) {
            // Se detecta el punto decimal
            if (c == '.')
                foundDot = 1;
        } else {
            // Si ya se encontró el punto, se suman los dígitos (si el caracter es un dígito)
            if (c >= '0' && c <= '9')
                sum += (c - '0');
        }
    }

    printf("La suma de los dígitos decimales es: %d\n", sum);
    return 0;
}

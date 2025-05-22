#include <stdio.h>

int main(void) {
    char string1[80], string2[80];
    printf("Ingrese dos cadenas: ");
    scanf("%s%s", string1, string2);
    misterio1(string1, string2);
    return 0;
}


void misterio1(char *s1, const char *s2){
    while (*s1 != '\0')
        ++s1;
    for (; *s1 = *s2; s1++, s2++)
        ;
}

/*hace lo siguiente:

Copia el carácter actual de s2 a la posición actual de s1.
Avanza ambos punteros (s1++, s2++).
Continúa hasta que el carácter copiado sea el carácter nulo (\0), es decir, hasta el final de la cadena s2.
En resumen:
Copia toda la cadena s2 (incluyendo el \0) al final de s1.
Esto concatena s2 al final de s1.*/
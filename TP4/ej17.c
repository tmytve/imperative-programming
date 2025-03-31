// EJERCICIO DE PARCIAL
// Escribir la macro ELAPSED que al recibir dos medidas de tiempo en horas y minutos retorne la cantidad de minutos transcurridos. No usar funciones de la biblioteca estándar

#define ELAPSED(h1, m1, h2, m2, mtotal) if ((h2) > (h1)) {                                     \
        (mtotal) = (60 * ((h2) - (h1)) + ((m2) - (m1)));    \
    } else if ((h1) > (h2)) {                              \
        (mtotal) = (60 * ((h1) - (h2)) + ((m1) - (m2)));    \
    } else {                                               \
        if ((m2) > (m1)) {                                 \
            (mtotal) = ((m2) - (m1));                      \
        } else {                                           \
            (mtotal) = ((m1) - (m2));                      \
        }                                                  \
}

#include <stdio.h>
int main(void) {
    int a;
    ELAPSED(4, 15, 7, 50, a);
    printf("%d\n" , a);
}
// mtotal = (60 * (h2 - h1) + (m2 - m1))

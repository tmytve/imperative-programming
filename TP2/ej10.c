/*Escribir un programa que lea una variable entera que representa un intervalo de tiempo expresado en segundos. Realizar la conversión para imprimir en la salida estándar el equivalente en horas, minutos y segundos. No utilizar variables auxiliares.*/
#include <stdio.h>
#include "../getnum.h"

int main(void) {
    int segundos = getint("Inserte la cantidad de segundos: ");

    printf("Tiempo en horas: %f\n", (double)segundos/3600);
    printf("Tiempo en minutos: %f\n", (double)segundos/60);
    printf("Tiempo en segundos: %d\n", segundos);

}

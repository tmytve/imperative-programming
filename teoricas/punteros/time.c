/*
Se necesita una funcion que dado un tiempo expresado en segundos, retorne la cantidad de horas minutos y segundos:
*/

#include <stdio.h>
void time(int *horas, int *minutos, int *segundos);
int main(void) {
    int segundos, minutos, horas;
    segundos = 5000;
    time(&horas, &minutos, &segundos);
    printf("%dhs\t%dmin\t%dseg\n", horas, minutos, segundos);

}

void time(int *horas, int *minutos, int *segundos){
    *horas = *segundos / 3600;
    *segundos %= 3600;
    *minutos = *segundos / 60;
    *segundos %= 60;
}

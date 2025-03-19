/*Escribir un programa que lea una variable tipo float  representando una velocidad en m/s, e imprima en la salida estándar el equivalente en km/h. Utilizar una única variable. */

#include <stdio.h>
#include "../getnum.h"

int main(void){
    float v = getfloat("Ingrese la velocidad en m/s: ");
    printf("Elquivale a %f km/h", v*3.6);
}

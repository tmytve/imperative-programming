/*
Escribir, en no más de 5 líneas, un programa que defina y utilice una macro con un parámetro para calcular el volumen de una esfera. El programa deberá calcular el volumen para esferas de radios de 1 a 10 cm., e imprimir los resultados en forma tabulada.	
Volumen de la Esfera = ( 4/3 ) * π * r^3
*/
#include <stdio.h>
#include <math.h>
#include "../getnum.h"
#define volEsfera(radio) ((4.0/3.0) * M_PI * (pow(radio, 3)))
int main(void){
    double radio = getfloat("Igrese el radio: ");
    double a = volEsfera(radio); 
    if ((radio >= 1) && (radio <= 10)){
        printf("Es radio de la esfera es %.2f\n", a);
    }else{
        printf("Debe ingresar un valor entre 1 y 10\n");
    }
} 
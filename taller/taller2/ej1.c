/*
Escribir un programa que permita al usuario ingresar los coeficientes de una
ecuación cuadrática y luego imprima la solución.
-Si la ecuación no es cuadrática, deberá indicarle el error al usuario.
-Si la ecuación es cuadrática pero tiene raíces complejas, mostrar un mensaje
informando la situación
*/
#include <stdio.h>
#include <math.h> //al compilar agregar -lm
#include "getnum.h"

int main(void) {
    float a = getfloat("a = ");
    float b = getfloat("b = ");
    float c = getfloat("c = ");

    if (a == 0)
    {
        printf("La ecuacion no es cuadratica\n");
    }
    else 
    {
        double discriminante = pow(b, 2)-4*a*c;
        double raiz1 = (-b+sqrt(discriminante))/2*a;
        double raiz2 = (-b-sqrt(discriminante))/2*a;
        if (discriminante>=0)
        {
            printf("Las raices de la ecuacion cuadratica son: r1 = %.2f y r2 = %.2f", raiz1 , raiz2);
        }
        else{
            printf("La ecuacion tiene raices complejas");
        }
        
    }
        

}

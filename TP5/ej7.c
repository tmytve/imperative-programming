/*
Escribir una función real para calcular aproximadamente el valor de ex  por  medio de la serie  1 + x + x2 / 2! + x3 / 3! + ....... Dicha función recibe como parámetros de entrada el valor de x. (En no más de 10 líneas)
Hacer un programa que invoque a la función y escriba el resultado de la misma y el valor de la función exp(x) de C.
	
¿Cómo harías para fijar la precisión de cálculo de la función?
*/
#include <stdio.h>
#include <math.h> // -lm
#include "../getnum.h"
float ex(int x);
int main(void) {
    int num = getint("x = ");
    printf("%f\n",ex(num));
}

float ex(int x){
    float ans = 1;
    for (int i = 1; i < 10; i++){
        ans += (pow(x,i))/(tgamma(i+1)); //tgamma es la funcion factorial en <math.h> se invoca con n+1 . Ej tgamma(6) devuelve 5!
    }
    return ans;
}
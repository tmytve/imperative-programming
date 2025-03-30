/*
Escribir un programa (en no más de 10 líneas) que calcule el valor de la constante matemática e utilizando la fórmula  e = 1 + 1/1!  + 1/2! + 1/3! +...  e imprima una tabla que indique cantidad de términos de la serie y el resultado parcial, con el siguiente formato:
	N		e
	1		1
	2		2
	3		2.5

¿Qué criterio utilizaría para detener la secuencia? ( No usar cantidad fija de términos ni preguntarle al usuario la cantidad de términos. Tampoco tendría sentido comparar con el verdadero valor de e).
*/
#include <stdio.h>
//voy a detener la secuencia cuando el termino sea insignificativo en los digitos de e
int factorial(int num){
    int total = 1;
    if(num > 0){
        for (int i = 1; i <= num; i++){
            total *= i;
        }
    }
    return total;
}

int main(void) {
    float e = 1;
    for (int i = 1; i < 10; i++){
        e += 1.0/factorial(i);
    }
    printf("%f\n", e);
}




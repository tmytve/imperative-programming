/*
Escribir un programa que ofrezca un menú con las siguientes opciones:
Simplificar una fracción
Sumar dos fracciones
Terminar la ejecución

	   Si se elige la primera opción se le solicitará numerador y denominador de la fracción y se imprimirá la fracción simplificada (algunos de ellos podrían ser negativos). Si se opta por la segunda, se le solicitará dos fracciones y se imprimirá la suma de las mismas, también simplificada. Obviamente con la tercera opción finaliza la ejecución del mismo. Escribir una función para cada item del menú. (No más de 20 líneas para main y no más de 10 líneas para las funciones del menú).
	Pista: Escribir y usar la función DivisorComunMaximo.
*/
#include <stdio.h>
#include <stdlib.h>
#include "../getnum.h"
#include <math.h>
int mcd(int a, int b);
int menu(int opcion);
int sumarFracciones(int numerador1, int denominador1, int numerador2, int denominador2);
int simplificar(int numerador, int denominador);
int main(void) {
    int opcion = getint("Oprima 1 para simplificar una fraccion\n""Oprima 2 para sumar dos fracciones\n""Oprima 3 para terminar la ejecucion\n");
    menu(opcion);
}

int menu(int op){
    if (op == 1){
        int numerador = getint("Numerador = ");
        int denominador = getint("Denominador = ");
        simplificar(numerador, denominador);
    }else if (op == 2){
        int numerador1 = getint("Numerador fraccion 1 = ");
        int denominador1 = getint("Denominador fraccion 1 = ");
        int numerador2 = getint("Numerador fraccion 2 = ");
        int denominador2 = getint("Denominador fraccion 2 = ");
        sumarFracciones(numerador1, denominador1, numerador2, denominador2);
    }else if (op == 3){
        printf("Terminando la ejecucion...\n");
    }
    
    
    return 0;
}


int mcd(int a, int b){
    while (b != 0){
        int aux = a % b;
        a = b;
        b = aux;
    }
    return a;    
}

int simplificar(int numerador, int denominador){
    int maximoComunDivisor = mcd(numerador, denominador);
    numerador /= maximoComunDivisor;
    denominador /= maximoComunDivisor;
    printf("Fraccion simplificada: %d/%d\n", numerador, denominador);
    //return numerador, denominador;
    return 0;
}

int sumarFracciones(int numerador1, int denominador1, int numerador2, int denominador2){
    int num, den;
    num = (numerador1 * denominador2) + (numerador2 * denominador1);
    den = abs(denominador1 * denominador2)/mcd(denominador1, denominador2); // mcm = |a*b| / mcd(a,b)
    printf("Suma de %d/%d + %d/%d = %d/%d\n", numerador1, denominador1, numerador2, denominador2, num, den);
    simplificar(num, den);
    return 0;
}



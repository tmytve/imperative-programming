/*Escribir un programa para hallar las raíces de una función matemática en un intervalo cerrado, recorriéndolo de forma tal que el intervalo quede dividido en 100000 (cien mil) particiones o subintervalos. Ejemplo: si el intervalo es [1, 50000] deberá evaluar la función en los puntos 1, 1.5, 2, etc. (también se tomarán como válidos los puntos 1, 1.49999, etc ).
El programa deberá solicitar los extremos del intervalo, imprimiendo los resultados en la salida estándar. La función a evaluar recibe y devuelve un valor real y está dada por la macro FUNCION.
La función que realice la búsqueda de las raíces debe recibir como parámetros una estructura que represente al intervalo,  regresando en su nombre una estructura que empaquete un arreglo con aquellas particiones donde haya raíces y la dimensión de dicho arreglo.
Para detectar una raíz se deben considerar dos casos:
Que la función cambie de signo entre dos puntos: En ese caso se agrega al arreglo una partición con ambos puntos.
Que la función se haga cero en un punto (considerando un error de EPSILON): En ese caso la partición que se agrega al arreglo de resultados está formada por el punto anterior al que se detectó como raíz y el próximo que no lo sea.
*/
#define FUNCION(x) sin(x)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "getnum.h"
#define EPSILON 1e-4

typedef struct {
    double inicio;
    double fin;
} Intervalo;

typedef struct {
    Intervalo *subintervalo;
    int cantidad;
} Raices;


void buscaRaices(Intervalo intervalo, Raices *raices);
int main(void) {
    double inicio = getint("Inicio del intervalo: ");
    double final = getint("Final del intervalo: ");
    Intervalo inter;
    Raices raices;
    inter.inicio = inicio;
    inter.fin = final;
    buscaRaices(inter, &raices);
    for (int i = 0; i < raices.cantidad; i++){
        printf("[%.5f,%.5f] ", raices.subintervalo[i].inicio, raices.subintervalo[i].fin);
    }
    free(raices.subintervalo);
}

void buscaRaices(Intervalo intervalo, Raices *raices){
    raices->subintervalo = malloc(100000*sizeof(Intervalo));
    int k = 0;
    double prev = intervalo.inicio;
    double f_prev = FUNCION(prev);

    double paso = (intervalo.fin - intervalo.inicio) / 100000.0;
    for (double i = intervalo.inicio + paso; i <= intervalo.fin; i+=paso){
        double f_i = FUNCION(i);
        if (f_prev * f_i < 0 || fabs(f_prev) < EPSILON){
            raices->subintervalo[k].inicio = i - paso;
            raices->subintervalo[k].fin = i + paso;
            k++;
        }
        prev = i;
        f_prev = f_i;
    }


    raices->cantidad = k;    
}




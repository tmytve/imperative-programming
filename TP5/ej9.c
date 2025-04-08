/*
Escribir un programa (en no más de 15 líneas) para encontrar raíces de funciones en un intervalo dado. Se deberá recorrer el intervalo a incrementos de 0.001, evaluando la función en cada paso y escribiendo por salida estándar los puntos que son raíces. Los extremos del intervalo serán de tipo real y su valor estará dado por constantes del programa. 
Tener en cuenta no sólo el caso en el que el resultado de evaluar la función sea cero, sino también aquellos puntos en los cuales la función cambia de signo.
*/
#include <stdio.h>
#include <math.h>
#define MIN -10
#define MAX 10
#define TOL 0.00001

int main(void) {
    float x, f, prev_x, prev_f;
    
    // Inicializamos en el primer punto del intervalo.
    prev_x = MIN;
    prev_f = pow(prev_x, 2) - 1;
    
    for (x = MIN + 0.001; x <= MAX; x += 0.001) {
        f = pow(x, 2) - 1;
        
        // Si el valor de la función es muy cercano a cero, lo consideramos raíz.
        if (fabs(f) < TOL) {  
            printf("Raíz en x = %f\n", x);
        }
        // Si hay cambio de signo entre f(prev_x) y f(x), se pasó por cero.
        else if (prev_f * f < 0) {
            // Se puede imprimir un intervalo donde se encuentra la raíz.
            printf("Cambio de signo entre x = %f y x = %f\n", prev_x, x);
        }
        
        prev_x = x;
        prev_f = f;
    }
    
    return 0;
}
//Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, escribir una función para obtener la mayor diferencia entre dos elementos consecutivos. (En no más de 5 líneas). Tener en cuenta que los números pueden ser negativos. En caso de que el vector tenga un solo elemento deberá retornar como diferencia el valor cero.
#include <stdio.h>
#include <math.h>
#define DIM 7
float maxDif(const float vec[7]);
int main(void) {
    float vec[DIM] = {2, 5, 6, 20, 15, 14, 11};
    float maxDifValor = maxDif(vec);
    printf("La diferencia maxima es: %.0f\n", maxDifValor);
}

float maxDif(const float vec[7]){
    float max = fabs(vec[0] - vec[1]);
    int dif;
    for (int i = 0; i < DIM-1; i++){
        dif = fabs(vec[i] - vec[i+1]);
        if (dif > max){
            max = dif;
        }
    }
    return max;
}

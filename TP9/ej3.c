//Escribir una función recursiva productoEsc que reciba tres parámetros de entrada representando dos vectores de números reales de igual tamaño y su dimensión. La función debe regresar en su nombre el producto escalar de los vectores recibidos.
#include <stdio.h>
double productoEscalar(double vec1[], double vec2[], int dim){
    //caso base: dim == 0
    if(dim == 0) return 0;

    //paso recursivo:
    return (vec1[dim-1] * vec2[dim-1]) + productoEscalar(vec1,vec2,dim-1);
}


int main(void) {
    double vector1[] = {1.0, 2.0, 3.0};
    double vector2[] = {4.0, 5.0, 6.0};
    int n = sizeof(vector1) / sizeof(vector1[0]);
    double resultado = productoEscalar(vector1, vector2, n);
    printf("El producto escalar es: %.2lf\n", resultado);
    return 0;
}

// Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) y el exponente (entero), y devuelva el valor de dicha potencia (En no más de 10 líneas). Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1.

#include <stdio.h>
float potencia(double base, int exp);
int main(void) {
    printf("%f\n", potencia(2,-4));
}
float potencia(double base, int exp){
    float resultado = 1.0;
    if (exp == 0){
        return 1;
    }else if (exp > 0){
        for (int i = 1; i <= exp ; i++){
            resultado *= base;
        }
    }else{
        exp *= -1;
        for (int i = 1; i <= exp ; i++){
            resultado *= base;
        }
        resultado = 1.0/(resultado);
    }
    return resultado;
}




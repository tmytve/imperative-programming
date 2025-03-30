/*
Dado un entero que representa un número binario positivo (todos sus dígitos son cero o uno), imprimir por salida estándar  el equivalente decimal
*/
#include <stdio.h>
#include "../getnum.h" // ../getnum.c al compilar
#include <math.h> //-lm al compilar
int polinomio(int num){
    int suma = 0;
    int i = 0;
    while(num!=0){
        int digito = num%10;
        if (digito != 0 && digito != 1){
            printf("Error: el numero ingresado no es binario\n");
            return -1;
        }
        num = num/10;
        suma += digito*pow(2, i); //se puede hacer con decalaje (preguntar!!)
        i++;
    }
    return suma;
}
int main(void) {
    int num = getint("Escribe el numero binario: ");
    int resultado = polinomio(num);
    if (resultado != -1)
    {
        printf("El equivalente en decimal es: %d\n", resultado);
    }
    return 0;
}

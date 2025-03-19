#include <stdio.h>
#define palabra "ultima prueba"

int
main(void)
{
    int num1 = 53, num2 = 4;
    float num3 = 6.874;

    printf("num1= %10d\n", num1); //deja 10 espacios vacios e imprime el valor del entero num1
    printf("num2= %010d\n", num2); //completa 10 espacios con ceros e imprime el entero num2
    printf("num1= %-10d\n", num1); //deja 10 espacios como el primero pero con el - alinea el valor entero num1 a la izquierda
    printf("num1+num2= %5i\n", num1 + num2); //deja 5 espacios e imprime la suma de num1 y num2
    printf("num1+num2= %5f\n", num1 + num2); //el compilador falla porque espera un float y recibe un int
    printf("num3= %-3.2f\n", num3); //??????
    printf("num1= %-4d\nnum2= %-4d\nnum3= %3.1f\n", num1,num2, num3); //redondea el float num3 a un decimal
    printf("num3(como entero)= %d\n", num3); //??????
    printf("num1 / num2 = %d\n", num1 / num2);//divide num1 por num2
    printf("num2 / num1 = %d\n", num2 / num1); //hace la division entera de num2 por num1
    printf("esta es la %s\n", palabra); //usa 'palabra' definida al comienzo del codigo

    return 0;
}
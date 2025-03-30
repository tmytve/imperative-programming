/*
Leer un número entero e indicar cuántos dígitos de ese número son iguales a 5.  Repetir para el caso de ser un número real, indicando cuántos 5 tiene en su parte entera y cuántos en su parte decimal. (En no más de 10 líneas el primer caso, y no más de 25 el segundo caso)
*/
#include <stdio.h>
#include "../getnum.h"
int main(void) {
    long long int num = getint("Ingrese un numero: ");
    int fiveCounter = 0;
    int digito;
    while (num!=0){
        digito = num%10;
        num = num/10;   
        if (digito == 5)
        {
            fiveCounter++;
        }
    }
    printf("Cantidad de cincos: %d\n", fiveCounter);
//preguntar por que si pongo un numero muy grande no cuenta los 5s correctamente (hip: overflow)
}

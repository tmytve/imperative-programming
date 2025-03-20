/*
Una empresa paga a su personal de venta en base a comisiones.  El personal de ventas recibe $300 por semana más un porcentaje de las ventas brutas de esa semana.  El porcentaje a aplicar depende del total vendido: si la venta no supera los $1000, no hay porcentaje, hasta $2000 es un 5%, hasta $4000 es un 7%, y más de $4000 es un 9%.  
Por ejemplo, un vendedor que vende $5000 en una semana, recibe $300 más 9% de $5000, o sea un total de $750.  
Hacer un programa en C que lea una única variable que indique la suma vendida en una semana, e imprima por salida estándar  el monto total a cobrar. Si la suma vendida es un valor incorrecto pedir un nuevo valor. (En no más de 15 líneas)
*/

#include <stdio.h>
#include "../getnum.h"

#define SUELDO_BASE 300

int main(void) {
    ///El total lo inicializamos en el sueldo base
    double total, ventas;

    do {
        ventas = getdouble("Ingresar las ventas del mes: $");
        if (ventas <= 0) printf("Ingresar un monto mayor a cero\n");
    } while(ventas <= 0);

    total = SUELDO_BASE;
    if (ventas > 4000){
        total += ventas * 0.09;
    } else if (ventas > 2000){
        total += ventas * 0.07;
    } else if (ventas > 1000) {
         total += ventas * 0.05;
    }

    printf("El monto total a cobrar es: $%.2f\n", total);

    return 0;
}

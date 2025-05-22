#include <stdio.h>

void swap(int  *num1, int *num2);
int main(void) {
    int x, y;  //*px, *py;
    x = 3;
    y = 5;
    swap(&x, &y);
    /*
    Ejecutar la funcion swap asi es lo mismo que hacer:
        px = &x;
        py = &y;
        swap(px, py);
    */
}


void swap(int  *num1, int *num2){
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
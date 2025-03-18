#include <stdio.h>

int
main(void)
{
    int c = 5;
    int a, b = c;
    a = b + c;
    return 0;
}

//Errores al compilar:
//void va entre () no []
//declara primero la variable c = 5 y despues se dice que b = c
//return va sin :
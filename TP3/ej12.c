//Escriba enunciados for que impriman las siguientes secuencias de valores
#include <stdio.h>

int main(void) {

// a)   3,8,13,18,23
    for (int i = 3; i < 24; i+=5)
    {
        printf("%d,", i);
    }
    printf("\n");

// b)   20,14,8,2,-4,-10

        for (int i = 20; i >= -10; i-=6)
    {
        printf("%d,", i);
    }
    printf("\n");

// c)   19,27,35,43,51
        for (int i = 19; i <= 51; i+=8)
    {                                      
        printf("%d,", i);
    }
    printf("\n");

    return 0;

}

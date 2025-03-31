//Escribir un programa que reciba texto por la entrada estandar y envie el mismo texto pasado a mayuscula y sin espacios
#include <ctype.h>
#include <stdio.h>

int main(void) {
    int text;
    while ((text = getchar()) != EOF){
        if (!isspace(text)){
            putchar(toupper(text));
        }
    }
}

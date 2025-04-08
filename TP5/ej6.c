/*
Escribir un programa que ofrezca las siguientes opciones para accionar sobre un caracter leído desde la entrada estándar. Utilizar distintas funciones (con no más de 4 líneas) para cada una de las opciones y una función para el menú de opciones:

Convertir de mayúscula a minúscula. 
Convertir de minúscula a mayúscula. 
Imprimir el carácter siguiente. 
Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
*/

#include <stdio.h>
#include <ctype.h>
#include "../getnum.h"
#include <assert.h>
int menu(unsigned char c);
int main(void) {
    unsigned char c = getchar();
    assert(isalpha(c));
    menu(c);
}

int menu(unsigned char c){
    int op = getint("Ingrese: \n1 para convertir de mayuscula a minuscula.\n2 para convertir de minuscula a mayuscula\n3 para imprimir el caracter siguiente\n4 para Imprimir la siguiente letra en forma circular\n");
    assert(op!=1||op!=2||op!=3||op!=4);    
    if (op == 1){
        putchar(toupper(c));
    }else if (op == 2){
        putchar(tolower(c));
    }else if (op == 3){
        putchar(c + 1);
    }else if (op == 4){
        if (isalpha(c) && (c != 'z') && (c != 'Z')){
            putchar(c + 1);
        }else if (c == 'z'){
            putchar('a');
        }else if (c == 'Z'){
            putchar('A');
        }
    }
    return 0;
}


//Escribir una función "palotes" que reciba un entero cant sin signo y envíe en forma recursiva a la salida estándar cant  "palotes". Si recibió cero, no imprime nada, si recibió 4, la salida debe ser "||||"  (las comillas no deben imprimirse)
#include <stdio.h>
int palotes(unsigned int cant);
int main(void) {
    palotes(5);
    printf("\n");
}

int palotes(unsigned int cant){
    //caso base: recibe 0
    if (cant == 0)
        return 0;
    
    //paso recursivo:
    printf("|");
    return palotes(cant-1);
}
//Escriba y ejecute un programa que imprima todos los múltiplos de 10 (10, 20, 30, 40, etc.)  en no más de 5 líneas ¿Qué sucede cuando ejecuta este programa?
#include <stdio.h>

int main(void) {
    int num = 10;
    while (num>0){
        num += 10;
        printf("%d, \n", num);
    }
    
}
//se genera un bucle infinito con todos los nu,tiplos de 10
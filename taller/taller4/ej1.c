/*
● Hacer un programa que genere una letra mayúscula aleatoria y un número
aleatorio N entre 1 y 256.
● Luego, deberá invocar a una función que lea un texto hasta N caracteres como
máximo (si aparece antes EOF, termina la lectura) y retorne la cantidad de
veces que dicha letra aparece en mayúscula o en minúscula.
● Ejemplos para cuando el texto es: “Había una vez un avestruz muy vivo,
vivísimo que se llamaba Victor”
    ○ Si se genera letra ‘V’ y N =101 la función retornaría: 7.
    ○ Si se genera letra ‘A’ y N=5 la función retornaría 2.
*/
#include <stdio.h>
#include "random.h"
#include <ctype.h>
int apariciones(int numRandom, int asciiAleatorio);
int main(void) {
    randomize();
    randNormalize();
    int numRandom = randInt(1,256);
    int mayus = randInt('A', 'Z');
    putchar(mayus);
    printf("Cantidad de veces que aparece la letra: %d\n", apariciones(numRandom, mayus));

}

int apariciones(int numRandom, int mayus){
    int counter = 0, i = 0, c;
    while ((c = getchar()) != '\n' && i<=numRandom) {
        if (toupper(c) == mayus){
            counter++;
        }
        i++;
    }
    return counter;
}







/*Simular un juego de naipes de 52 cartas, en el cual se mezcle el mazo y se tomen las 5 primeras cartas, indicando si se obtuvo alguna de las siguientes configuraciones:
    -PAR:  hay sólo dos de las cinco cartas con igual valor
    -PIERNA:  hay sólo tres de las cinco cartas de igual valor
    -POKER: hay cuatro cartas con igual valor
*/
#include <stdio.h>
#include "random.h"
typedef struct{
    int valor;
    char palo;
} Carta;

Carta mazo[52];

void mezclarCartas(Carta mazo[]){
    randomize();
    randNormalize();
    for (int i = 0; i < 52; i++){
        int j = randInt(0,i);
        Carta temp  = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }   
}

int hayPar(int conteo[]){
    for (int i = 0; i < 14; i++){
        if (conteo[i] == 2){
            return 1;
        }
    }
    return 0;
}

int hayPierna(int conteo[]){
    for (int i = 0; i < 14; i++){
        if (conteo[i] == 3){
            return 1;
        }
    }
    return 0;
}

int hayPoker(int conteo[]){
    for (int i = 0; i < 14; i++){
        if (conteo[i] == 4){
            return 1;
        }
    }
    return 0;
}

void inicializarMazo(Carta mazo[]) {
    char palos[] = {'C', 'D', 'T', 'P'}; //corazon, trebol, pica, y diamante
    int k = 0;
    for (int p = 0; p < 4; p++) {
        for (int v = 1; v <= 13; v++) {
            mazo[k].valor = v;
            mazo[k].palo = palos[p];
            k++;
        }
    }
}

int main(void) {
    Carta mazo[52];
    inicializarMazo(mazo);
    mezclarCartas(mazo);

    // tomo primeras 5 cartas como mano
    Carta mano[5];
    for (int i = 0; i < 5; i++)
        mano[i] = mazo[i];

    // muestro la mano
    printf("Mano: ");
    for (int i = 0; i < 5; i++)
        printf("%d%c ", mano[i].valor, mano[i].palo);
    printf("\n");

    // cuento repeticiones de valores
    int conteo[14] = {0};
    for (int i = 0; i < 5; i++)
        conteo[mano[i].valor]++;

    if (hayPoker(conteo))
        printf("POKER\n");
    else if (hayPierna(conteo))
        printf("PIERNA\n");
    else if (hayPar(conteo))
        printf("PAR\n");
    else
        printf("Nada especial\n");

    return 0;
}
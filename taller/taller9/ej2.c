/*Hacer un programa que genere aleatoriamente el movimiento de una partícula en el
plano 2D y registre en un arreglo cada una de las posiciones que fue tomando hasta volver
al origen de coordenadas.*/
#include <stdio.h>
#include "random.h"
#define maxMove 5
#define minMove -5
typedef struct {
    int x;
    int y;
} tPunto2D;
typedef tPunto2D *tPosiciones;

int main(void) {
    
}

void randMove(tPunto2D *var){
    randomize();
    randNormalize();
    var->x += randInt(minMove, maxMove);
    var->y += randInt(minMove, maxMove);
}

void saveMove(tPunto2D *var, tPosiciones *pos){
    
}


void movimientos(tPunto2D *var,tPunto2D *tPosiciones){
    do{
        tPosiciones
    } while (var->x != 0 && var->y != 0);
    
    
}


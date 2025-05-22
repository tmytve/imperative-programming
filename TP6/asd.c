#include <stdlib.h>
int randNormalize(void){
    return rand()/((double) RAND_MAX + 1);
}

int randInt(int izq, int der){
    if (izq > der){
        int aux = izq;
        izq = der;
        der = aux;
    }
    return randNormalize()*((der - izq) + izq);
}
/*Una partícula realiza un camino aleatorio dentro de un círculo de acuerdo a la siguientes reglas :
En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
x = x - 1
x = x + 1
y = y - 1
y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).

	Considerando cada punto como una estructura de componentes cartesianas y teniendo en cuenta que el tiempo se mide con un contador que se incrementa  en cada paso de la partícula, escribir un programa que para distintos tamaños de círculos determine experimentalmente la relación entre el tiempo requerido para terminar la caminata y el valor del radio.

Mostrar los valores hallados mediante una tabla cuyas columnas sean:
Radio
Tiempo
Relación (radio / tiempo )
*/
#include <math.h>
#include <stdio.h>
#include "random.h"
#define r 10
#define IN_CIRCLE(x,y,r) ((x)*(x) + (y)*(y) <= (r)*(r))
#define maxMove 1
int randEntre(int n1, int n2);

typedef struct{
    int x;
    int y;
} Particula;

typedef Particula *p1;
void randomMove(Particula *p1);

int main(void) {
    randomize();
    randNormalize();
    Particula p = {1,1};
    int counter = 0;
    do{
        randomMove(&p);
        counter++;
    } while (IN_CIRCLE(p.x, p.y, r));
    printf("Posicion final: (%d, %d)\n", p.x, p.y);
    printf("Tiempo: %d\n", counter);
    
}

void randomMove(Particula *p1){
    if (randEntre(2,3) == 2){
        p1->x += randEntre(-maxMove, maxMove);
    }else{
        p1->y += randInt(-maxMove, maxMove);    
    }   
}

int randEntre(int n1, int n2){
    return randInt(0,1)? n1 : n2;
}


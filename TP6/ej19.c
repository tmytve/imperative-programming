/*
Una fila es amiga de otra si todos los elementos de una fila están incluidos en otra. Por ejemplo:
    F1= 1 2 2 3 
    F2= 0 1 2 3 
    F3= 1 2 3 4 
F1 es amiga de F2 pues todos los elementos de F1 están incluidos en F2
F2 no es amiga de F1 pues el número 0 presente en F2 no está incluido en F1
F1 es amiga de F3 pues todos los elementos de F1 están incluidos en F3
F3 no es amiga de F1 porque el número 4 presente en F3 no está incluido en F1

Una matriz es amiga de otra si todas las filas de la primera matriz son amigas de alguna fila de la segunda matriz.

Se pide escribir la función sonAmigas que reciba los siguientes parámetros:
m1: la primera matriz de enteros 
fils1: la cantidad de filas de la primera matriz de enteros
m2: la segunda matriz de enteros
fils2: la cantidad de filas de la segunda matriz de enteros

Nota 1: Se cuenta con la constante simbólica COLS que indica la cantidad de columnas de la primera y segunda matriz de enteros.
Nota 2: Todas las filas tienen sus elementos ordenados de manera no descendente (cada elemento es menor o igual al siguiente)

La función debe retornar:
1: si la primera matriz es amiga de la segunda
2: si la segunda matriz es amiga de la primera
0: en cualquier otro caso

Si ambas son amigas, la función puede retornar 1 ó 2.

*/
#include <stdio.h>
#include <assert.h>
#define COLS 4

int filaAmiga(int vec1[], int vec2[]);
int sonAmigas(int m1[][COLS], int fils1, int m2[][COLS], int fils2);

int main(void){
  int m1[][COLS] = {{0,1,3,2}, {4,6,5,6}, {9,8,7,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,9,8,7}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);

    puts("OK!");
  return 0;
}
//Este codigo funciona tanto para matrices con filas ordenadas como matrices con filas desordenadas.(ej 19) 

int sonAmigas(int m1[][COLS], int fils1, int m2[][COLS], int fils2){
    int counter1 = 0, counter2 = 0, M1AmigaDeM2 = 0, M2AmigaDeM1 = 0;
    //para cada fila de la matriz 1
    for (int i = 0; i < fils1; i++){
        //inicializo flag en 0 (asumo que la fila NO tiene fila amiga)
        int tieneAmiga = 0;
        //para cada fila de la matriz 2
        for (int j = 0; j < fils2; j++){
            //chequeo si la fila de la matriz 1 esta incluida en la fila de la matriz 2
            if (filaAmiga(m1[i], m2[j])){
                //si encuentro alguna fila de la matriz 2 donde la fila de la matriz 1 esta incluida, entonces prendo la flag
                tieneAmiga = 1;
                break;
            }
        }
        //si la flag esta encendida (la fila de la matriz 1 que estoy analizando tiene una fila amiga en la matriz 2) => incremento el contador 1
        if (tieneAmiga)
            counter1++;
    }

    //misma logica para la vuelta
    for (int i = 0; i < fils2; i++){
        int tieneAmiga = 0;
        for (int j = 0; j < fils1; j++){
            if (filaAmiga(m2[i], m1[j])){
                tieneAmiga = 1;
                break;
            }
        }
        if (tieneAmiga)
            counter2++;
    }
    
    //para que dos matrices sean amigas, TODAS la filas de m1 tienen que tener un amigo en m2, entonces cheuqueo si la cantidad de filas que tienen amigos, es la misma cantidad de filas que tiene la matriz
    if (counter1 == fils1)
        M1AmigaDeM2 = 1;
    
    //lo mismo para la matriz 2
    if (counter2 == fils2)
        M2AmigaDeM1 = 1;
    
    
    if ((M1AmigaDeM2 && !M2AmigaDeM1) || (M1AmigaDeM2 && M2AmigaDeM1)){
        return 1;
    }else if (M2AmigaDeM1 && !M1AmigaDeM2){
        return 2;
    }
    
    return 0;
}

int filaAmiga(int vec1[], int vec2[]){
        //para cada elemento del vec1
        for (int i = 0; i < COLS; i++){
            int encontrado = 0;
            //busco si existe en vec2
            for (int j = 0; j < COLS; j++){
                if (vec1[i] == vec2[j]){
                    encontrado = 1;
                    break;
                }
            }
            //si algun elemento no se encuentra => las filas no son amigas
            if (!encontrado){
                return 0;
            }
        }
    return 1;
}
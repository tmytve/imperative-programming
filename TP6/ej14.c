/*Escribir la función contiene que reciba dos vectores de enteros y la dimensión de cada uno y retorne:
1 si todos los elementos del primer vector están en el segundo
2 si todos los elementos del segundo vector están en el primero
0 en caso contrario*/
#include <stdio.h>
#include <assert.h>
int contiene(int vec1[], int dimVec1, int vec2[],  int dimVec2);
int main(void) {
    //int vec1[] = {1,1,1,1};
    //int vec2[] = {1,2,3,4};
    int vec1[] = {1,6,5,3,2};
    int vec2[] = {1,2};
    int dimVec1 = sizeof(vec1)/sizeof(vec1[0]);
    int dimVec2 = sizeof(vec2)/sizeof(vec2[0]);
    int inclusion = contiene(vec1,dimVec1 ,vec2 , dimVec2);
    printf("%d \n", inclusion);


  assert(contiene(vec1, 5, vec2, 2)==2);
  assert(contiene(vec2, 2, vec1, 5)==1);
  assert(contiene(vec1, 1, vec2, 2)==1);
  assert(contiene(vec1, 0, vec2, 2)==1);
  assert(contiene(vec1, 5, vec2, 0)==2);
  
  int vec3[] = {1,2,3,4,5,6};
  int vec4[] = { 10, 20, 30, 1, 2};
  int vec5[] = {1,1,1,1,1,2,1,2};
  int vec6[] = {1,2,3};

  assert(contiene(vec1, 5, vec3, 6)==1);

  int cnt = contiene(vec1, 0, vec3, 0);
  assert(cnt ==1 || cnt==2);

  assert(contiene(vec2, 2, vec4, 4)==2);
  assert(contiene(vec2, 2, vec4, 5)==1);
  assert(contiene(vec4, 5, vec2, 2)==2);

  assert(contiene(vec5, 8, vec6, 3)==1);
  assert(contiene(vec6, 3, vec5, 8 )==2);

  puts("OK!");
}

int contiene(int vec1[], int dimVec1, int vec2[],  int dimVec2){
    int contador = 0;
    if (dimVec1 > dimVec2){
        for (int i = 0; i < dimVec2; i++){
            int encontrado = 0;
            for (int j = 0; j < dimVec1; j++){
                if (vec1[j] == vec2[i]){
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado){
                return 1;
            }
            
        }
        return 2;
    }

    if (dimVec2 > dimVec1){
        for (int i = 0; i < dimVec1; i++){
            int encontrado = 0;
            for (int j = 0; j < dimVec2; j++){
                if (vec1[i] == vec2[j]){
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado){
                return 2;
            }
            
        }
        return 1;
    }

    if (dimVec1 == dimVec2){
        int count1 = 0, count2 = 0;
        //veo si todos los elementos de vec1 estan en vec2
        for (int i = 0; i < dimVec1; i++){
            for (int j = 0; j < dimVec2; j++){
                if (vec1[i] == vec2[j]){
                    count1++;
                    break;
                }
            }
        }

        //veo si todos los elementos de vec2 estan en vec1
        for (int i = 0; i < dimVec2; i++){
            for (int j = 0; j < dimVec1; j++){
                if (vec1[j] == vec2[i]){
                    count2++;
                    break;
                }
            }
        }

        if (count1 == dimVec1)
            return 1;

        if (count2 == dimVec2)
            return 2;
        
        
    }
    return 0;

}

/*
El error con la version anterior es que antes siempre que encontraba un elemento de un vector en otro sumaba
el contador, entonces is tenia vec1={1,1,1,1} y vec2={1,2,3,4} me retornaba 2 diciendo que el vec2 esta incluido en el vec1
cosa que no tiene sentido, pero lo hacia ya que al recorrer cada elemento del vec1 y compararlo con el vec2 notaba que el 1 Si
estaba en el vec2 entonces incrementaba el contador++ cuatro veces, y al comparar con la dimension del vec2 coincidia, pero 
sin embargo estaba mal ya que vec2 ⊈ vec1
*/

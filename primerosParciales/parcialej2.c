void copiaVec(int vecAux[],int vec[], unsigned int dim);
int sinRep(int vec[]){
    int i = 0, k = 0;
    while(vec[i] != -1){
        if(vec[i] > vec[++i]){
            vec[k++] = vec[i];            
        }else{ //si no es mayor, es igual, ya que recibe vec ordenado de forma desc. (con rep)
            i++;
        }
    }
 
    vec[k] = -1;

    return k;
}
 
void copiaVec(int vecAux[],int vec[], unsigned int dim){
    for(int i = 0; i < dim; i++){
       vec[i] = vecAux[i];
    }
}


#include <stdio.h>

int main(void) {
    int vec[] = {8,7,6,5,5,5,4,3,2,2,-1};
    int dim = sizeof(vec)/sizeof(vec[0]);
    sinRep(vec);
    for (int i = 0; i < dim; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

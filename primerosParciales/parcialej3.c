void contar(int vec[], unsigned int dim, int *suma, int *cantPares, int *cantImpares){
    *cantPares = 0;
    *cantImpares = 0;
 
    if(dim == 0){
        *suma = 0;
    }
 
    for(int i = 0; i < dim; i++){
        *suma += vec[i];
        
        if(vec[i] % 2 == 0){
           (*cantPares)++;
        }else{
           (*cantImpares)++;
        }
    }
}

#include <stdio.h>

int main(void) {
    int *suma ,*cantPares, *cantImpares;
    int vec[] = {1,2,3,4,5,6,7,8};
    int dim = sizeof(vec)/sizeof(vec[0]);
    contar(vec, dim, &suma, &cantPares, &cantImpares);
    printf("%d %d %d\n", suma, cantImpares, cantPares );
}

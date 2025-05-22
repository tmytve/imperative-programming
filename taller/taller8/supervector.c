/*Implementar un programa que lea de la entrada estándar hasta EOF y genere el
supervector que todo lo puede guardar. Luego imprimir el contenido del vector en
salida estándar.*/

#include <stdio.h>
#include <stdlib.h>
#define BLOQUE 10
int main(void) {
    char c;
    char *arr = NULL;
    int dim = 0;
    int flag = 1;

    for (; flag != 0; dim++){
        if (dim % BLOQUE == 0)
            arr = realloc(arr, (dim+BLOQUE)*sizeof(arr[0]));
        
        if ( (c = getchar()) != '\n' ){
            arr[dim] = c;
        }else{
            flag = 0;
        }
        
    }


    //implime el vector
    for (int i = 0; i < dim; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
    
}




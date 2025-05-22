#include <stdio.h>
void eliminaRepetidos(char vec[]){
    int j = 0;
    for (int i = 0; vec[i] != '\0'; i++){
        if (vec[i] != vec[i+1])
            vec[j++] = vec[i];

    }
    vec[j] = 0;
}


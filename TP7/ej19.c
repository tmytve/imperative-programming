//Escribir la función copiaPrefijo que dado un string s y un número entero n retorne en su nombre un nuevo string con los primeros n caracteres del string s. Si la longitud de s es menor a n debe retornar una copia de s.. ¿Qué cuidado debe tener el usuario de esta función?
#include <string.h>
char * copiaPrefijo(char *s, int n){
    char * resp = malloc((n+1)*sizeof(char));
    strncpy(resp, s, n);
    resp[n] = '\0';
    return resp;
}

//El usuario debe hacer un free(resp) luego de usar la funcion copiaPrefijo para liberar la memoria de resp


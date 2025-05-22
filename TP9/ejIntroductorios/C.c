//Escribir una versión recursiva de la función strchr
#include <stdio.h>
char strchrRecursiva(const char *str, char c){
    //caso base: str[0] = '\0'
    if(*str == '\0')
        return NULL;
    if(*str == c)
        return (char *)str;
    //paso recursivo:
    return strchrRecursiva(str + 1, c);
}
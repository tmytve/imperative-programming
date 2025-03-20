/*
Leer un caracter desde la entrada estándar e imprimir por salida estándar si el caracter es una letra o no y, en caso de ser una letra, indicar si es letra mayúscula o minúscula, sin tener en cuenta el caracter ‘ñ’. (En no más de 15 líneas)
*/

#include <stdio.h>

int main(void) {
    printf("Escriba un caracter: ");
    unsigned char caracter = getchar();
    if ((caracter>='A' && caracter<='Z'))
    {
        printf("%c es una letra mayuscula\n", caracter);
    }
    else if ((caracter>='a' && caracter<='z'))
    {
        printf("%c es una letra minuscula\n", caracter);
    }
    else{
        printf("%c no es una letra\n", caracter);
    }
    return 0; //preguntar que diferencia hay que ponga el return 0; a que no lo ponga
}



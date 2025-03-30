/*
Leer desde la entrada estándar una serie de caracteres, hasta que uno de ellos no sea una letra ni un espacio.  Luego imprimir por salida estándar  el menor alfabéticamente de ellos  respetando si fue mayúscula o minúscula, indicando además cuántas letras eran mayúsculas y cuántas minúsculas. No considerar el carácter ‘ñ’ como letra. (En no más de 15 líneas)
*/
#include <stdio.h>
#include "../getnum.h"
#define DELTA ('a' - 'A')
#define TRUE 1
#define FALSE !TRUE

int main(void) {
    int c, countUp=0, countLow=0, lowest='z', isLowestUpper, isCurrentUpper;
    while (((c = getchar()) >='A' && c<='Z')||(c>='a'&&c<='z')|| c == ' ')
    {
        if (c != ' '){  //analizo c porque no es un espacio
            if (c>='a' && c<='z') // c es minuscula
            {
                countLow++;
                isCurrentUpper = FALSE;
            }else{ //c es mayuscula
                countUp++;
                isCurrentUpper = TRUE; //levanto el flag
                c += DELTA; //paso c a minuscula
            }
            if (c<lowest)
            {
                lowest = c;
                isLowestUpper = isCurrentUpper;
            }
            
        }
        
    }
    printf("#Mayusculas = %d\n#Minusculas = %d\n", countUp, countLow);
    printf("La menor alfabeticamente es %c\n", isLowestUpper ? lowest - DELTA : lowest);
    
    
    
}

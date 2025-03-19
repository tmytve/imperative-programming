/*
El siguiente programa funciona correctamente en algunas computadoras, pero no en otras. Indicar cuál puede ser el problema
*/

#include <stdio.h>
 
int main(void) 
{
     char c;
     while ((c = getchar()) != EOF) 
          putchar(c);
     
    return 0;
}
// ?????
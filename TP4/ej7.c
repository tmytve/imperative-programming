#include <stdio.h>
#define isdigit(c) ((c >= '0') && (c <= '9'))
int main(void) {
    int letra;
	letra = getchar();
	if ( isdigit(letra) )
		printf("Es un dígito\n");
}


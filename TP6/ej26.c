//Escribir la función insertaDesde, que recibe dos strings (null terminated) y un carácter. Al primer string se le inserta el segundo a partir de la primera aparición del carácter indicado. Si el carácter no aparece en el primer string, el mismo no debe ser alterado
#include <stdlib.h>

char * encuentraCaracter(char * s, char c) {
	while(*s) {
		if(*s == c) {
			return s;
		}
		s++;
	}
	return NULL;
}

void
copiaCadena(char * d, const char * f) {
	while(*d++ = *f++) {
		;
	}
}

void 
insertaDesde(char * s1, const char * s2, char c) {
	char * pos = encuentraCaracter(s1, c);
	if(pos != NULL)		
		copiaCadena(pos, s2);
}


/* solucion utilizando string.h */
#include <string.h>

void insertaDesde(char * s1, const char * s2, char c) {
    char * pos = strchr(s1, c);
    if(pos != NULL)		
        strcpy(pos, s2);
}
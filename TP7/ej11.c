#include <stdio.h>
#include <ctype.h>
#include <string.h>
char * aMayusculas(char * s){
	char * t;
	for(t = s; *t = toupper(*t); t++)
		;
	
	return s;
}

void resize(char *p, unsigned int bytes){
    p = realloc(p, bytes);
}

int main(void) {
    char *p = NULL;
    resize(p, 100);
    strcpy(p, "Hello World");
    aMayusculas(p);
    printf("%s\n", p);

    return 0;
}

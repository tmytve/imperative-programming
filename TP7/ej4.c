#include <stdio.h>
int main(void) {
    char string1[80], string2[80];
    printf("Ingrese dos cadenas: ");
    scanf("%s%s", string1, string2);
    misterio1(string1, string2);
    return 0;
}

int misterio2(const char *s){
    int x = 0;
    for (; *s != '\0'; s++)
        ++x;
    return x;
}

//cuenta la longitud del string
/*
Completar el programa para que permita separar los 8 bits de la variable var de a pares, en 4 variables char distintas trasladando los bits a la posision menos significativa.
- Si el caracter es var=0xD8, entonces guarda 1101 1000
-Luego separo trasladando bits a la posision menos significativa
-en var1 deberia guardar 00000011, en var2 deberia guardar 00000001,
en var3 deberia guardar 00000010, y en var4 deberia guardar 00000000
*/
#include <stdio.h>

int main(void){
    unsigned char var, var1, var2, var3, var4;
    var =0xD8;
    var1= var >> 6 & 0x03 ;
    var2= var >> 4 & 0x03 ;
    var3= var >> 2 & 0x03  ;
    var4= var & 0x03  ;
    
    printf("var  = 0x%X\n", var);
    printf("var1 = %d\n", var1);
    printf("var2 = %d\n", var2);
    printf("var3 = %d\n", var3);
    printf("var4 = %d\n", var4);
    return 0;
}
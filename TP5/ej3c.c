//El siguiente programa detecta si un boleto de 5 cifras es capicúa, para ello utiliza una función llamada lugar que dado dos números  n y k, retorna el k-ésimo dígito contando desde la derecha del número n. Los ceros a izquierda se descartan.
#include <stdio.h>
#include "../getnum.h"
#include <math.h>
#include <assert.h>

int lugar (int num, int pos);
int main( void ){
	int boleto, esCapicua = 1;
	int  j;
    do{ // ej3 item c
        boleto = getint("Ingrese un número de 5 dígitos: ");
    } while (boleto < 10000 || boleto > 99999);
    
	for (j=1; j<=2; j++)
		if ( lugar(boleto, j) != lugar(boleto,5-j+1)){	
 			esCapicua=0;
			break;
		}
	printf("El boleto %ses capicúa\n",(esCapicua)? "":"no ");
	return 0;
}

int lugar( int num, int pos ){	
    return (num / (int)pow(10, pos-1)) % 10;
}
/*
La siguiente función intenta ser una instrumentación del algoritmo de Euclides para calcular el MCD de dos números, pero no siempre da el resultado correcto. Indicar errores y corregirlos para que funcione correctamente.

int dcm (int a, int b){
	int auxi;
	while (auxi>0){	
		a = b;
            b = auxi;
            auxi = a % b ;
    }
	return a;
}

*/

int dcm (int a, int b){
	int auxi;
	while (auxi > 0){	
		auxi = a % b ;
        a = b;
        b = auxi;
    }
	return a;
}
#include <stdio.h>

int main(void) {
    printf("%d\n", dcm(20, 75));
}
//El error es el orden en el que se hacian las operaciones, primero se guarda el resto de dividir a a por b, luego se iguala a a b y por ultimo se iguala b al resto anterior, cuando el resto sea 0 finaliza
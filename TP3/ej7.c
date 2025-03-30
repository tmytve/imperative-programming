//Decir qué envía el siguiente programa a la salida estándar.
#include <stdio.h>
#include "../getnum.h"
int
main(void)
{
	int i, j, n = 0, suma = 0;


	while( n <= 0 )
		n = getint("Ingrese cantidad de elementos:");


	for(i=1; i<=n; i++)
	{
		j = getint("Ingrese valor %d:",i);
		suma += j;
	}


	printf("El resultado es : %.2f\n", suma / (float) j);
	return 0;	
}
//el codigo le pide al usuario una n cantidad de elememntos.
//Entonces el programa procede a pedirle n numeros enteros al usuario, y devuelve la division de
// la suma de estos n numeros por el ultimo numero ingresado


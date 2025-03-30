#include <stdio.h>

int main(void) {
// a) 
    /* float x = 1/3; el error esta en que esto devuelve 0 ya que se le pasan dos valores enteros.
	while(x != 0.52 ) el ciclo se repite infititamente ya que x nunca va a ser exactamente 0.52 ya que 1.0/3 es periodico. se debe usar un <=
		x += .01; */
        //forma correcta:
    float x = 1.0/3; //alguno de los dos valores debe ser float para que se devuelva float
	while(x <= 0.52 ) 
		x += .01;



// b)

    /*
    for( y = .1; y != 1.0; y+= .1) falta el float para declarar la variable y no se puede representar exactamente el 0.1 por lo que la suma      nunca dara 1.0, para corregirlo se puede poner un <= en el for
		printf("%f\n", y);
    */

// c)
int n = 5 ;

switch (n)
{ 
		case 1:   
printf("El número es 1\n");
        //falta un break en el case 1
		case 2: 
printf("El número es 2\n");
		 	break;
		default:  
printf("El número no es ni 1 ni 2\n");
			break;
	}

// d)
int c, mayor;
mayor = 0;
while ( c = getchar() != EOF ) //falta parentesis en (c = getchar())
	{
		if ( c > mayor )
			mayor = c;
}
printf ("El mayor es %c\n",mayor);


}


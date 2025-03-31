/*
Decidir, en caso de ser posible, con qué valor termina cada una de las variables en los siguientes programas. En caso de haber errores de compilación, corregirlos.
*/
// a)
#define PI  3.1415
#include <stdio.h>
int main(void){
	int a = 0;
	int b;
    b = PI + a++;
    printf("%d %d\n", a,  b );
	return 0;
} // a = 0      b = 3 pues la variable b esta declarada como entero, y no suma a++ porque incrementa despues, deberia ser ++a

// b) 
#define PI 3.14
int main(void){	
	float a=0;
	float b;
 	b = a + PI++;
 	return 0;
} // Error de compilacion pues un define no se puede incrementar

// c)
#define CUBO(x)  x * x * x
int cubo (int num);
int main(void){
	int a=4, b, c;
	b = CUBO(a+1);
	c = cubo(a+1);
	return 0;
}
int cubo ( int num ){
	return num * num * num;
} // a=4 b=13 c=125

// d)
#define CUBO(x)  ((x) * (x) * (x))
int cubo (int num);
int main(void){
	int a=3, b, c, d, e, f;
	b = CUBO( ++a );
    c = CUBO( a++ );
    d = 3;
	e = cubo ( ++d );
	d = 3;
	f = cubo ( d++ );
	return 0;
}
int cubo ( int num ){
	return num * num * num;
} // a=6 b=120 c=336 d=3 e=64 f=27

// e)
#define DIVISION(x, y, z)	{int i; \
				  for(z = 0, i = x-y; i >= 0; z++, i-= y); \
					}
int main( void ){
	int a, b, c, m, n, p, x, y, z;
	a = 20; b=5; c=3;
	DIVISION(a, b, c);
	m=5; n=4; p=2;
	DIVISION(m++, n--, p);
	x=15; y=3; z=0;
	DIVISION(x, y, 0);
	return 0;
} //   a=20 b=5 c           




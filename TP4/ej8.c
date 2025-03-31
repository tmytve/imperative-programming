/*
Encontrar y corregir los errores en cada uno de los siguientes segmentos de programa.
*/
// a)
/*
void
f1 (void){
printf ("Dentro de la función f1\n");
 	void
 	f2(void){
 		printf ("Dentro de f2\n");
 	}
}
En C no se puede definir una funcion adentro de otra, se deben definir por separado
*/
//Forma correcta: 
/*
#include <stdio.h>
void f2(void) {
    printf("Dentro de f2\n");
}
void f1(void) {
    printf("Dentro de la función f1\n");
    f2();
}
int main(void) {
    f1();
    return 0;
}*/


// b)
/*
int suma (int x, int y){
int respuesta;	
respuesta = x + y;
}
Falta que la funcion retorne respuesta, o podria directamente retornar x + y
Forma correcta:

int suma (int x, int y){
    return x + y;
}

*/

// c)
/*
int suma (int n);{
	if (n <= 0)
		return 0;
	else
		n + 1;
}
El ; despues del argumento no va. Falta return en el n + 1

int suma (int n){
	if (n <= 0)
		return 0;
	else
		return n + 1;
}
*/

// d)
/*
void f2( float a ){
    float a;
    printf ("%f\n",a*a);
}
No es necesario redeclarar la variable si esta como argumento en la funcion
Forma correcta:
void f2( float a ){
    printf ("%f\n",a*a);
}
*/

// e)
/*
void f3 ( int letra ){
	printf('Letra: ');
	putchar(letra);
	putchar("\n");
}
El printf va con comillas dobles
Forma correcta: 
void f3 ( int letra ){
	printf("Letra: ");
	putchar(letra);
	putchar("\n");
}
*/

// 

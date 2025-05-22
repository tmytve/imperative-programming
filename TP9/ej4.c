/*Se desea escribir funciones que dado un número entero mayor o igual a cero, indiquen si el mismo es par o impar. ¿Qué ocurre si se las define de la siguiente forma?*/
#include <stdio.h>
int esPar(unsigned n);
int esImpar(unsigned n);

int esPar(unsigned n){
	return ! esImpar(n);
}

int esImpar(unsigned n){
	return ! esPar(n);
}


int main(void) {
    printf("%d\n", esImpar(5));
}

/*Este código no funciona porque las funciones esPar y esImpar se llaman recursivamente entre sí sin un caso base.
Esto provoca recursión infinita y el programa termina con un desbordamiento de pila (stack overflow).

¿Cómo debería ser?
Debes agregar un caso base para detener la recursión:*/
int esPar(unsigned n){
    if (n == 0) return 1; // 0 es par
    return !esPar(n - 1);
}

int esImpar(unsigned n){
    if (n == 0) return 0; // 0 no es impar
    return !esImpar(n - 1);
}
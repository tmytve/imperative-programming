/*
Modificar los siguientes fragmentos de código por un fragmento equivalente pero mejorándolo. Este ejercicio se podría titular "No hagan esto en sus casas, o al menos en los parciales y TPE". si bien funcionan no son de buen estilo, y un mal estilo suele ir acompañado de errores o código más difícil de mantener
*/
#include <stdio.h>
#include "../getnum.h"

// a) 
//int a = getint("Ingrese un número entero:");
//if ( a > 0 )
//    printf("Es mayor que cero\n");
//if ( a < 0 )
//    printf("Es menor que cero\n");
//if ( a == 0)
//   printf("Es igual a cero\n");

//Forma correcta:
int a = getint("Ingrese un numero entero: ");
if (a == 0){
    printf("Es igual a cero\n");
}else if (a > 0)
{
    printf("Es positivo\n");
}else{
    printf("Es negativo\n");
}

// b)
// int a = ( b > 0 ) ? 0 : 1;
//Forma correcta: 
int a  = (b < 0);

// c)
/*
int a = 0;
while(1) {
   f(a);   // f es una función
   a = a + 1;
   if ( a >= 10 )
      break;
}
*/
int a = 0;
while(1) {
   f(a);   // f es una función
   a++;
   if ( a >= 10 )
      break;
}


// d)
/*
if ( b > 0 )
    a = 1;
else
    a = 0;
*/
// Forma correcta: 
int a = (b > 0)

// e)
/*
if ( a > 0 )
   if ( b < 0 )
      c = 10;
   else
      c = 20;
else
      c = 20;
*/
int c = (a > 0)? (b < 0 ? 10 : 20) : 20;

// f)
/*
int i = 0;
int a = 10;
for ( ; i < 10; ) {
    a += getint("");
    i += 1;
}
   printf("El valor de a es %d\n", a);
*/
int a = 10;
for (int i = 0; i < 10; i++){
    a+=getint("");
}
printf("El valor de a es %d\n", a);

// g)
/*
int suma;
   for ( int i=0; i < 100; i++) {
      if ( i==0 )
         suma = getint("Ingrese la base:");
      else
         suma += i;
   }
   printf("La suma es %d\n", a);
*/
int suma  = getint("Ingrese la base: ")
for (int i = 1; i < 100; i++){
    suma += i;
}
printf("La suma es %d\n", a);

// h)
/*
// Dado un vector ordenado (lo veremos en detalle más adelante)
// no vacío, cuenta cuántos elementos distintos hay
cant = 0; 
for(int i=0; i<dim; i++){
   if(i>=1){
     	 if(last != v[i]) {
	     last=v[i];
	     cant++;
	 }
    } else {
    	 last=v[i];
	 cant++;
    }
}
*/

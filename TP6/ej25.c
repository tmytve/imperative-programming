/*
Escribir una función que devuelva un subvector de un arreglo de caracteres, recibiendo sólo los siguientes parámetros:
arregloIn: vector de entrada, null terminated.
arregloOut: vector de salida null terminated.
desde, hasta: valores enteros, representan las posiciones de valores a copiar.
dimMax: dimensión máxima del vector de salida (incluyendo el cero).

 	Dicha función debe almacenar en arregloOut los elementos de arregloIn cuyos índices estén comprendidos entre desde y hasta inclusive y colocar el valor cero al final. La cantidad máxima de elementos a copiar está dada por el parámetro dimMax. En caso de que la cantidad de valores a copiar supere dimMax, se copiarán solamente dimMax - 1 valores.
	Si alguno de los parámetros es erróneo o la posición desde esté fuera de los límites del arreglo de entrada, la función debe retornar el valor cero y no alterar el arreglo de salida, caso contrario debe retornar la cantidad de elementos copiados (sin contar el cero final).
*/
#define MIN(a,b) ((a)<(b))?(a):(b)
#include <string.h>
unsigned int copiaSubVector(const char * arregloIn, char * arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax){
	int cantidadCar = 0;
	if (desde <= hasta && desde >= 0 && dimMax > 0){
		for (int i = desde; i <= hasta && arregloIn[i]!='\0' && cantidadCar < dimMax-1; i++){
			arregloOut[cantidadCar++] = arregloIn[i];	
		}
		arregloOut[cantidadCar] = '\0';
		return cantidadCar;
	}
	return 0;
}



//TEST
#include <stdio.h>
#include <assert.h>
#include <string.h>


int main(void) {
  char s[100];
  assert(copiaSubVector("un texto", s,0,0,1)==0);
  assert(strcmp(s, "")==0);
  assert(copiaSubVector("un texto", s,0,0,10)==1);
  assert(strcmp(s, "u")==0);
  assert(copiaSubVector("un texto", s,0,10,1)==0);
  assert(strcmp(s, "")==0);

  assert(copiaSubVector("un texto", s,45,130,1)==0);


  assert(copiaSubVector("un texto", s,0,130,2)==1);
  assert(strcmp(s, "u")==0);

  assert(copiaSubVector("un texto", s,0,130,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,9)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,2,5,8)==4);
  assert(strcmp(s, " tex")==0);
  
  assert(copiaSubVector("un texto", s,45000,130000,10)==0);

  printf("OK!\n");
  return 0;
}
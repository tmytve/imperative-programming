//Detectar errores de compilación en el siguiente programa:
#define N 10
#define M 20

int main(void){
	int dim = 7;
	int vectorA[ M * N]; //se declara que el tamaño del vectorA es de 200 (va de 0 a 199). No es ningun error, pero lo aclaro para despues
	int vectorB[ -10 ]; //El tamaño de un array tiene que ser positivo
	int vectorC[ 10.0 ]; //El tamaño de un array tiene que ser un entero positivo
	int vectorD[dim];
	vectorC[2.5] = 'a'; //no existen indices decimales en un array. Cada posicion tiene valor entero arrancando desde 0
	vectorB[-1] = 5; //no existen indices negativis en un array
	vectorA['0'] = 10;
	vectorC[vectorA[48]] = 5.5;
	vectorA[1000] = 0; //ERROR de compilacion, se intenta accdeder a un elemento en la posision 1000 cuando solo llega hasta 199 el vectorA
	vectorA[M * N] = 10;
	return 0;
}

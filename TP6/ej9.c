/*
Se desea calcular la desviación estándar de un arreglo de números enteros. Los números del arreglo toman valores entre 0 y 15 inclusive, por lo que para almacenar cada número se utilizarán solo 4 bits, pudiendo almacenar dos números en un solo byte. 
Para representar dicho arreglo se utilizará un vector de caracteres, donde cada elemento del vector contendrá dos números (uno en los cuatro bits superiores y el otro en los cuatro bits inferiores). Escribir una función que reciba un arreglo como el mencionado anteriormente y la cantidad de números que contiene y retorne en su nombre la desviación estándar de los números recibidos.

	Ejemplo: Si se define el siguiente arreglo:


	unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
 
	Representa al arreglo de los elementos: 3, 7, 15, 2, 0, 3, 4, 10, 15, 15.

*/

#include <stdio.h>
#include <math.h> // -lm
double derivEstandar(unsigned char arr[], int n);
double promedio(int arr[], int dim);
int main(void) {
    unsigned char arr[] = {0x37, 0xF2, 0x03, 0x4A, 0xFF};
    int dimArr = sizeof(arr)/sizeof(arr[0]);
    printf("%f\n", derivEstandar(arr, dimArr));
}

double derivEstandar(unsigned char arr[], int n){
    int lenNewArr = 2 * n;
    int arrEnDecimales[lenNewArr];
    int j = 0;
    for (int i = 0; i < n; i++){
        //Extraigo bits superiores e inferiores
        int superior = arr[i] >> 4;
        int inferior = arr[i] & 0x0F;
        //Los guardo en un nuevo arreglo
        arrEnDecimales[j++] = superior;
        arrEnDecimales[j++] = inferior;
    }
    
    //Desviacion estandar
    double media = promedio(arrEnDecimales, lenNewArr);
    double sumaDeCuadrados = 0.0;
    for (int i = 0; i < lenNewArr; i++){
        double diferencia = arrEnDecimales[i] - media;
        sumaDeCuadrados += pow(diferencia, 2);
    }

    return sqrt(sumaDeCuadrados / lenNewArr);
}

double promedio(int arr[], int dim){
    double suma = 0.0;

    for (int i = 0; i < dim; i++){
        suma += arr[i];
    }
    return suma/dim;
}

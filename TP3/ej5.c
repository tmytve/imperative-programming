#include <stdio.h>
#include <string.h>

//invoco funciones que voy a usar. Las defino despues del main
int esMayus(int a);
int esMinus(int a);
int esVocal(int a);


int main(void) {
    int a, b, c;
a = getchar();
b = getchar();
c = getchar();


if (esMayus(a) && !esVocal(a))
	printf("El caracter %c es una consonante mayúscula \n", a);
else 
if (esMinus(a) && !esVocal(a))
		printf("El caracter %c es una consonante minúscula \n", a);
else 
 		if (esVocal(a)) 
			printf("El caracter %c es una vocal \n", a);
		else
			printf("El caracter %c no es una letra \n", a);


if (b%2 == 0)
printf("El valor ASCII de %c es par \n", b);
	
if ((b>='0' && b<='9')){
	int digito = b - '0';
	if (digito%2 == 0)
	{
		printf("El caracter %c representa un dígito par \n", b);
	}
}
if (esVocal(c)||esMayus(c))
	printf("El caracter %c es una vocal o es mayúscula \n", c);
	
if (!esVocal(c) && ((c>='A'&&c<='Z')||(c>='a'&&c<='z')))
	printf("El caracter %c no es una vocal pero es letra \n", c); //es como decir 'el caracter es una consonante'

}


int esMayus(int a){
	if (a>='A' && a<='Z'){
		return 1;
	}
	else{
		return 0;
	}	
}
int esMinus(int a){
	if (a>='a' && a<='z'){
		return 1;
	}
	else{
		return 0;
	}
}
int esVocal(int a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
            a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}

//Indicar cuál de los fragmentos de código cuenta con un mejor estilo de programación.
// a)
int c1 = getchar();	
int c2 = getchar();	
c1 > c2 ? printf("%c es mayor\n", c1) : printf("%c es mayor\n", c2);	

// b)
int c1 = getchar();	
int c2 = getchar();	
printf("%c es mayor\n", c1 > c2 ? c1 : c2);


// c)
int c1, c2;	
printf("%c es mayor", (c1 = getchar()) > (c2 = getchar()) ? c1 : c2);

//La opcion b es la mas prolija y la que mejor se entiende ya que se declaran las variables
// antes del print y se usa el condicional adentro del printf


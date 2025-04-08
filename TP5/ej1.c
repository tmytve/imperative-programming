//Para cada punto, el código fuente es el único módulo que forma un programa ejecutable. Si hay errores indicarlos y corregirlos. Una vez corregido realizar el seguimiento de cada código e indicar qué valores se imprimen en cada caso

// a)

#include <stdio.h>
int a,b; 
void local ( void );             

int main ( void ){	
    a = 2; b = 3; 
    local(); // no se modifica el valor de a. Si el de b ya que la variable es global
 	printf(" a vale : %d\tb vale %d\n",  a, b ); // a=2 ; b=10
    return 0;
}


void local ( void ){	
    int a;  //esta variable es local de la funcion 'local' 
    a =  -5;   
    b = 10;                   
 	return ; 
}

// b) 
#include <stdio.h>
int a, b, c; 

void primero ( void );
void segundo ( void );
                        
int main ( void ){   
    a = 1;    
 	printf("El valor de c es %d", c ); // c = 0 (se inicializa en 0)
    segundo();
    printf ("El valor de a es %d, el de b es %d",a , b ); // a=2 ; b=-2
  	primero();      
    printf("El valor de a es %d, el de c es %d", a, c ); // a=3 ; c=0
	return 0;
}

void primero ( void ){ 	
    int a ;
 	a = 3;   
 	c = 0;
}
	 
void segundo ( void ){	
	int a ;
	c = 0;   
	a = 2;   
	b = -a;
}

// c)
#include <stdio.h>
 	
char letra; 
void segundo ( void );

int main( void ){	
    printf( "Ingrese un carácter : "); 
    letra = getchar();
    segundo();
    printf( " letra es : %c\n", letra );
    return 0;
}

void segundo( void ){	
    char letra; 
 	letra = 'X';
 	return;
}

// d)
#include <stdio.h>
static int  m;
int b;
static void este(void);
int main(void){	
    m = 2; 
    b = 3;                    
 	este();
    printf("m vale : %d", m );
    printf("b vale : %d", b );
 	return 0;
}

static void este(void){	
    static int m; 
 	m++; 
    b = - 3;
    printf( "Dentro de este() m vale %d y b vale %d", m, b);// ??????
 	return;
}

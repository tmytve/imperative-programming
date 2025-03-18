#include <stdio.h>

#define NRO 019

int
main(void)
{
	long i = NRO;
	printf("%ld\n",i);
	return 0;
}

//al tratarse de una constante definida en sistema octal
// no se puede compilar ya que hay un 9
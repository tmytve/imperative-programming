/*
La siguiente función recibe como parámetros de entrada las horas y los minutos que representan el momento de ingreso al trabajo de un empleado, y devuelve 1 ( verdadero ) si el empleado llegó a horario y 0 ( falso ) si llegó tarde. Las constantes ENT_HORA y ENT_MINUTOS están definidas fuera de la función e indican el horario esperado de entrada al trabajo.   Testearla, y de no funcionar correctamente, corregirla.
*/

int ENT_HORA = 8;
int ENT_MINUTOS = 30;
/*
int llegaTemprano (const int hora, const int minutos){
	return (hora <= ENT_HORA && minutos <= ENT_MINUTOS);
}
*/
//Esta funcion no sirve ya que si por ejemplo el empleado llega 7:40 y el horario de entrada es 8:30, llego temprano, sin embargo la funcion retorna 0 ya que los minutos son mayores. La forma correcta es la siguiente:
int llegaTemprano (const int hora, const int minutos){
	if ((hora < ENT_HORA) || (ENT_HORA == hora && minutos <= ENT_MINUTOS)){
        return 1;
    }else{
        return 0;
    }
}

#include <stdio.h>
int main(void) {
    printf("Llego %s\n", llegaTemprano(7, 50)? "temprano" : "tarde");
}


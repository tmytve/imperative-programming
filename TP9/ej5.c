/*Idem ejercicio anterior pero con las siguientes funciones. ¿En qué casos funcionan correctamente y en qué casos no?*/
int esPar(unsigned n);
int esImpar(unsigned n);


int esPar(unsigned n){
    if (n == 0)
        return 1;
    else
        return esImpar(n-1);
}


int esImpar(unsigned n){
    if (n == 1)
        return 1;
    else
        return esPar(n-1);
}

/*funciona correctamente solo para los valores 0 y 1.
Para otros valores, no distingue correctamente entre par e impar.*/
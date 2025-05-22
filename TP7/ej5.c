//Sean Nombre y Curso dos arreglos que contienen el nombre y el curso( ‘G’ o ‘H’) de cada uno de los alumnos de una materia. Escribir una función que reciba dichos arreglos como parámetros de entrada y retorne en parámetros de salida otros dos arreglos CursoG y CursoH con el nombre de los alumnos separados por curso. El string vacío en el nombre indica fin del arreglo.

#include <stdio.h>
#include <string.h>

void separaCursos(char *Nombre[], char Curso[], char *CursoG[], char *CursoH[]) {
    int g = 0, h = 0;
    for (int i = 0; Nombre[i][0] != '\0'; i++) {
        if (Curso[i] == 'G') {
            CursoG[g++] = Nombre[i];
        } else if (Curso[i] == 'H') {
            CursoH[h++] = Nombre[i];
        }
    }
    CursoG[g] = "";
    CursoH[h] = "";
}

int main(void) {
    char *Nombre[] = {"Ana", "Luis", "Sofi", "Pedro", ""};
    char Curso[] = {'G', 'H', 'G', 'H', '\0'};
    char *CursoG[10];
    char *CursoH[10];

    separaCursos(Nombre, Curso, CursoG, CursoH);

    printf("Curso G:\n");
    for (int i = 0; CursoG[i][0] != '\0'; i++) {
        printf("%s\n", CursoG[i]);
    }

    printf("Curso H:\n");
    for (int i = 0; CursoH[i][0] != '\0'; i++) {
        printf("%s\n", CursoH[i]);
    }

    return 0;
}
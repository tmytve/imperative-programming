/*Escribir un programa que realice la simulación de un bingo para dos jugadores, el cual imprimirá paso a paso la bolilla extraída y los números faltantes (que aún no salieron)de cada cartón. Las bolillas están representadas por los números del 1 al 90 y cada jugador tiene un cartón con 15 números distintos. Los cartones son generados por el programa en forma aleatoria. No es necesario conservar los números que se van marcando en cada cartón (cuando hay coincidencia con la bolilla extraída) 
El tipo de datos a utilizar para el cartón será :

		typedef  int TipoLinea[5];
		typedef  TipoLinea  TipoCarton [3]; 

GenerarCarton:
Descripcion: Genera un cartón de bingo en forma aleatoria.

Prametros: -carton
           -TipoCartonDe salida V.F.: 15 enteros distintos entre 1 y 90
*/
#include <stdio.h>
#include "random.h"

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton[3];

void generarCarton(TipoCarton carton);
int pertenece(TipoCarton carton, int numero);
int sacarBolilla(int *bolillero, int *cantBolillas);
int controlarLineas(TipoLinea linea);
int buscarBolilla(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int controlarCarton(TipoCarton carton, int bolilla);
int jugar(int bolillero[], TipoCarton jugador1, TipoCarton jugador2);

int main(void) {
    randomize();
    randNormalize();
    int bolillero[90];
    for (int i = 1; i <= 90; i++)
        bolillero[i] = i;

    TipoCarton jugador1, jugador2;
    generarCarton(jugador1);
    generarCarton(jugador2);

    printf("Cartón Jugador 1:\n");
    imprimirCarton(jugador1);
    printf("Cartón Jugador 2:\n");
    imprimirCarton(jugador2);

    int resultado = jugar(bolillero, jugador1, jugador2);

    if (resultado == 1)
        printf("¡Ganó el Jugador 1!\n");
    else if (resultado == 2)
        printf("¡Ganó el Jugador 2!\n");
    else if (resultado == 3)
        printf("¡Ambos jugadores hicieron bingo!\n");
    else
        printf("Nadie hizo bingo.\n");

    return 0;
}

void generarCarton(TipoCarton carton){
    //primero inicializo el carton en ceros
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            carton[i][j] = 0;
    int numero;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            do{
                numero = randInt(1,90);
            } while (pertenece(carton, numero));
            carton[i][j] = numero;
        }
    }
}

int pertenece(TipoCarton carton, int numero){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (numero == carton[i][j])
                return 1;
        }
    }
    return 0;
}

int sacarBolilla(int *bolillero, int *cantBolillas){
    int index = randInt(0, *cantBolillas - 1);
    int bolilla = bolillero[index];
    bolillero[index] = bolillero[*cantBolillas - 1];
    (*cantBolillas)--;
    return bolilla;
}

int controlarLineas(TipoLinea linea) {
    for (int i = 0; i < 5; i++) {
        if (linea[i] != 0)
            return 0;
    }
    return 1;
}

int buscarBolilla(TipoCarton carton, int bolilla) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (carton[i][j] == bolilla) {
                carton[i][j] = 0; // Marca la bolilla
                return 1;         // La encontro y la marco
            }
        }
    }
    return 0; // No la encontro
}

void imprimirCarton(TipoCarton carton) {
    for (int i = 0; i < 3; i++) {
        printf("Línea %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            if (carton[i][j] != 0)
                printf("%2d ", carton[i][j]);
        }
        printf("\n");
    }
}

int controlarCarton(TipoCarton carton, int bolilla) {
    // Marca la bolilla si esta en el cartón
    buscarBolilla(carton, bolilla);

    // Cuenta lineas completas
    int lineasCompletas = 0;
    for (int i = 0; i < 3; i++) {
        if (controlarLineas(carton[i]))
            lineasCompletas++;
    }
    return lineasCompletas;
}


int jugar(int bolillero[], TipoCarton jugador1, TipoCarton jugador2){
    int cantBolillas = 90;
    int bingo1 = 0, bingo2 = 0;
    int linea1 = 0, linea2 = 0;
    int lineaAunciada = 0;
    while (!bingo1 && !bingo2 && cantBolillas > 0){
        int bolilla = sacarBolilla(bolillero, &cantBolillas);
        printf("\nBolilla extraida: %d\n", bolilla);

        int lineas1 = controlarCarton(jugador1, bolilla);
        int lineas2 = controlarCarton(jugador2, bolilla);

        if (!lineaAunciada && (lineas1 > 0 || lineas2 > 0)){
            if (lineas1 > 0 && lineas2 > 0){
                printf("Ambos jugadores hicieron linea!!\n");
            }else if (lineas1 > 0){
                printf("Jugador 1 hizo la primera linea\n");
            }else{
                printf("Jugador 2 hizo la primera linea\n");
            }
            lineaAunciada = 1;
        }
        imprimirCarton(jugador1);
        imprimirCarton(jugador2);
        if(lineas1 == 3) bingo1 = 1;
        if(lineas2 == 3) bingo2 = 1;
    }
    return (bingo1 ? 1 : 0) | (bingo2 ? 2 : 0);
}

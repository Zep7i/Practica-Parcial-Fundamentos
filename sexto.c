/*
Desarrollar una funcion en c que reciba como parametros la estructura ya cargada y sus maximos logicos (de filas y columnas),
e imprima por pantalla el menor numero almacenado en la misma y la cantidad de veces que se repite dicho numero.
Evitar el uso de estructuras de datos e iteraciones innecesarias.
*/

#include <stdio.h>
#define CANTFILAS 3
#define CANTCOLS 4
typedef int Tmatriz[CANTFILAS][CANTCOLS];

void MenorMatriz(Tmatriz matriz, int ml_filas, int ml_columnas) {
    int acumulador=0, menor_matriz = matriz[0][0];
    int indice_fil, indice_col;

    for (indice_fil=0; indice_fil < ml_filas; indice_fil++) {
        for (indice_col=0; indice_col < ml_columnas; indice_col++) {
            if (matriz[indice_fil][indice_col] < menor_matriz) {
                menor_matriz = matriz[indice_fil][indice_col];
                acumulador = 1;
            } else if (matriz[indice_fil][indice_col] == menor_matriz)
                acumulador++;
        }
    }
    printf("El menor numero de la matriz es el %i y aparece %i veces\n", menor_matriz, acumulador);
}

int main() {
    Tmatriz matrizCargada = {
        {4,4},
        {4,4}
    };

    int filas = 2;
    int columnas = 2;

    MenorMatriz(matrizCargada, filas, columnas);

    return 0;
}
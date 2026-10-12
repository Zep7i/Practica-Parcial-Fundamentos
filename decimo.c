/*
desarrollar una funcion que reciba como parametros la estructura ya cargada
, sus maximos logicos (de filas y columnas) y un numero entero.
debe devolver al modulo invocante , la cantidad de columnas pares en las cuales el numero recibido
se encuentra presente.
*/

#include <stdio.h>
#define CANTCOLS 25
#define CANTFILAS 15
typedef int Tmatriz[CANTFILAS][CANTCOLS];

void MatchColumnasPares(Tmatriz matriz, int ml_filas, int ml_columnas, int numero, int *recuento) {
    int indice_col_par;
    int indice_fil = 0;
    int numero_encontrado = 0;

    (*recuento) = 0;
    for (indice_col_par = 1; indice_col_par < ml_columnas; indice_col_par += 2) {
        while (indice_fil < ml_filas && numero_encontrado == 0) {
            if (matriz[indice_fil][indice_col_par] == numero) {
                (*recuento)++;
                numero_encontrado = 1;
            }
            indice_fil++;
        }
        numero_encontrado = 0;
        indice_fil = 0;
    }
}


int main() {
    Tmatriz mat = {
        {1, 2},
        {4, 5},
        {7, 8},
        {10, 11}
    };
    int ml_fil = 4;
    int ml_col = 2;
    int num = 8;
    int recuento;

    MatchColumnasPares(mat, ml_fil, ml_col, num, &recuento);
    printf("El numero %i aparece en las columnas pares de la matriz %i veces.", num, recuento);
    return 0;
}
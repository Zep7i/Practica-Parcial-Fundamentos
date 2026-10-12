/*
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

Asumiendo que la estructura esta cargada en su totalidad, se solicita:
Desarrollar una funcion que reciba la estructura ya cargada y devuelva un vector
que contenga en cada posicion el minimo valor de cada fila.

Nota: CODIFICAR SOLAMENTE LA FUNCION SOLICITADA, NO EXTRAS.
*/

#include <stdio.h>
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

#include <stdio.h>

void MinimoFilas(TvecFilas matriz, int ml_filas, int ml_columnas) {
    TvecCols minimo_fila = {0}; // Inicializar el vector en cero.
    int min;
    for (int i=0; i < ml_filas; i++) {
        minimo_fila[i] = matriz[i][0];
        for (int j=0; j < ml_columnas; j++) {
            if (matriz[i][j] < minimo_fila[i])
                minimo_fila[i] = matriz[i][j];
        }
        printf("El menor numero de la fila %i/%i es %i\n", i+1, ml_filas, minimo_fila[i]);
    }
}

int main() {
    TvecFilas filas = {{12, 5, 35}, {4, 5, 6}, {73, 9, 8}, {1, 11, 12}};
    MinimoFilas(filas, 4, 3);

    return 0;
}
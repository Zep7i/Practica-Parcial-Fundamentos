/*
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

Asumiendo que la estructura esta cargada en su totalidad, se solicita:
Desarrollar una funcion que reciba la estructura ya cargada y devuelva un vector
que contenga en cada posicion el promedio de los elementos de cada fila 
(promedio de todas las columnas por cada fila)

Nota: CODIFICAR SOLAMENTE LA FUNCION SOLICITADA, NO EXTRAS.
*/

#include <stdio.h>
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

#include <stdio.h>

void PromedioFilas(TvecFilas matriz, int ml_filas, int ml_columnas) {
    TvecCols promedio = {0}; // Inicializar el vector en cero.
    int suma_filas;
    for (int i=0; i < ml_filas; i++) {
        suma_filas = 0;
        for (int j=0; j < ml_columnas; j++) {
            suma_filas += matriz[i][j];
        }
        promedio[i] = suma_filas / ml_columnas;
        printf("Promedio de la fila #%i/%i: %i\n", i+1, ml_filas, promedio[i]);
    }
}

int main() {
    TvecFilas filas = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    PromedioFilas(filas, 4, 3);

    return 0;
}
/*
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

Asumiendo que la estructura esta cargada en su totalidad, se solicita:
Desarrollar una funcion que reciba la estructura ya cargada y devuelva un vector
que contenga en cada posicion la suma de los elementos de cada fila 
(sumar las columnas por cada fila)

Nota: CODIFICAR SOLAMENTE LA FUNCION SOLICITADA, NO EXTRAS.
*/

#include <stdio.h>
#define cantcols 15
#define cantfilas 30
typedef int TvecCols[cantcols];
typedef TvecCols TvecFilas[cantfilas];

void SumaFilas(TvecFilas matriz, int ml_filas, int ml_columnas) {
    TvecCols suma = {0}; // Inicializar el vector en cero
    for (int contador1=0; contador1 < ml_filas; contador1++) {
        for (int contador2=0; contador2 < ml_columnas; contador2++) {
            suma[contador1] += matriz[contador1][contador2];
        }
        printf("Suma fila #%i/%i: %i \n", contador1+1, ml_filas, suma[contador1]);
    }
}


int main() {
    TvecFilas filas = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    SumaFilas(filas, 4, 3);

    return 0;
}
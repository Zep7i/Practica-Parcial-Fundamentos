/*
Dadas dos matrices A y B, escribir un programa que permita cargar sus dimensiones y sus datos.
El programa debe multiplicarlas (A.B) en caso de ser posible o devolver una señal si la operación no puede realizarse.
Para la estructura de datos considere un tamaño máximo de 10  (máximo entre 1 y 10)

Aclaración: para multiplicar matrices, la primera matriz debe tener igual columnas que filas tenga la segunda.
Devolver una matriz resultante.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_FIL 10
#define MAX_COL 10
typedef int TMatriz[MAX_FIL][MAX_COL];

void InicializarMatriz(TMatriz matriz, int filas, int columnas) {
    for (int i=0; i < filas; i++) {
        for (int j=0; j < columnas; j++){
            matriz[i][j] = 0;
        }
    }
}

void MultiplicarMatrices(TMatriz mat_a, int dim_fil_m1, int dim_col_m1, TMatriz mat_b, int dim_fil_m2, int dim_col_m2, TMatriz mat_c, bool multiplicable) {
    int indice_fil_mat_a, indice_fil_mat_b, indice_col_mat_b;

    InicializarMatriz(mat_c, dim_col_m1, dim_fil_m2);

    if (multiplicable == true) {
        for (indice_fil_mat_a = 0; indice_fil_mat_a < dim_fil_m1; indice_fil_mat_a++) {
            for (indice_col_mat_b = 0; indice_col_mat_b < dim_col_m2; indice_col_mat_b++) {
                for (indice_fil_mat_b = 0; indice_fil_mat_b < dim_fil_m2; indice_fil_mat_b++) {
                    mat_c[indice_fil_mat_a][indice_col_mat_b] += mat_a[indice_fil_mat_a][indice_fil_mat_b] * mat_b[indice_fil_mat_b][indice_col_mat_b];
                }
            }
        }
    }
}

bool EsMultiplicable(int dim_col_m1, int dim_fil_m2) {
    return dim_col_m1 == dim_fil_m2;
}

void CargarMatrices(TMatriz m1, TMatriz m2, TMatriz m3, int *dim_fil_m1, int *dim_col_m2) {
    int dim_col_m1=1, dim_fil_m2=1;
    int indice_fil_m1, indice_col_m1, indice_fil_m2, indice_col_m2;
    bool verificarMultiplicable = false;
    (*dim_fil_m1)=1;
    (*dim_col_m2)=1;

    printf("[Matriz #1] Ingrese la cantidad de filas: \n");
    scanf(" %i", dim_fil_m1);
    while ((*dim_fil_m1) < 1 || (*dim_fil_m1) > 10) {
        printf("[ERROR] Ingrese la cantidad de filas: \n");
        scanf(" %i", dim_fil_m1);
    }
    printf("[Matriz #1] Ingrese la cantidad de columnas: \n");
    scanf(" %i", &dim_col_m1);
    while (dim_col_m1 < 1 || dim_col_m1 > 10) {
        printf("[ERROR] Ingrese la cantidad de columnas: \n");
        scanf(" %i", &dim_col_m1);
    }
    printf("[Matriz #2] Ingrese la cantidad de filas: \n");
    scanf(" %i", &dim_fil_m2);
    while (dim_fil_m2 < 1 || dim_fil_m2 > 10) {
        printf("[ERROR] Ingrese la cantidad de filas: \n");
        scanf(" %i", &dim_fil_m2);
    }
    printf("[Matriz #2] Ingrese la cantidad de columnas: \n");
    scanf(" %i", dim_col_m2);
    while (*dim_col_m2 < 1 || *dim_col_m2 > 10) {
        printf("[ERROR] Ingrese la cantidad de columnas: \n");
        scanf(" %i", dim_col_m2);
    }
    for (indice_fil_m1=0; indice_fil_m1 < *dim_fil_m1; indice_fil_m1++) {
        for (indice_col_m1=0; indice_col_m1 < dim_col_m1; indice_col_m1++) {
            printf("[Matriz #1] Carga el numero de la fila #%i - Columna #%i -> ", indice_fil_m1+1, indice_col_m1+1);
            scanf(" %i", &m1[indice_fil_m1][indice_col_m1]);
        }
    }
    printf("[!] Datos cargados para la matriz #1\n");
    for (indice_fil_m2=0; indice_fil_m2 < dim_fil_m2; indice_fil_m2++) {
        for (indice_col_m2=0; indice_col_m2 < *dim_col_m2; indice_col_m2++) {
            printf("[Matriz #2] Carga el numero de la fila #%i - Columna #%i -> ", indice_fil_m2+1, indice_col_m2+1);
            scanf(" %i", &m2[indice_fil_m2][indice_col_m2]);
        }
    }
    printf("[!] Datos cargados para la matriz #2\n");
    verificarMultiplicable = EsMultiplicable(dim_col_m1, dim_fil_m2);
    if ( verificarMultiplicable != true)
        printf("[ADVERTENCIA!] Las matrices ingresadas no podrán ser multiplicadas.\n");
    else
        printf("[INFO] Las matrices pueden multiplicarse!\n");
    MultiplicarMatrices(m1, *dim_fil_m1, dim_col_m1, m2, dim_fil_m2, *dim_col_m2, m3, verificarMultiplicable);
}

int main() {
    TMatriz matriz1, matriz2, matriz3;
    int dim_fil_m1, dim_col_m2;
    int indice_fil_m1, indice_col_m2;

    CargarMatrices(matriz1, matriz2, matriz3, &dim_fil_m1, &dim_col_m2);

    for (indice_fil_m1 = 0; indice_fil_m1 < dim_fil_m1; indice_fil_m1++) {
        for (indice_col_m2 = 0; indice_col_m2 < dim_col_m2; indice_col_m2++) {
            printf("%i ", matriz3[indice_fil_m1][indice_col_m2]);
        }
        printf("\n");
    }
    return 0;
}
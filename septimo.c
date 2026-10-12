/*
funcion ejercicio_3 que reciba una matriz cargada con numeros enteros, que representan las cantidades de mililitros de lluvia por hora
de cada dia del mes de noviembre.
La funcion debe mostrar por pantalla el dia y el acumulado de ese dia, de aquellos dias que superen el promedio diario mensual.

Considerar que solo se puede recorrer una vez la matriz. Esta permitido utilizar un vector auxiliar.

Promedio diario mensual = 44.2ml
En el dia 1 han caido 51ml
En el dia 3 han caido 52ml
En el dia 30 han caido 45ml
*/

#include <stdio.h>
#define DIAS 30
#define HORAS 24
typedef int MatrizLluviaMensual[DIAS][HORAS];
typedef int VectorLluviaDiaria[DIAS];

void ejercicio_3(MatrizLluviaMensual matriz) {
    float promedio_mensual = 0;
    int suma_ml_dia = 0, suma_ml_mes = 0;
    int indice_dia, indice_horas;
    VectorLluviaDiaria lluvia_diaria = {0}; // Inicializo el vector en cero.
    
    for (indice_dia = 0; indice_dia < DIAS; indice_dia++) {
        for (indice_horas = 0; indice_horas < HORAS; indice_horas++) {
            suma_ml_dia += matriz[indice_dia][indice_horas];
        }
        suma_ml_mes += suma_ml_dia;
        lluvia_diaria[indice_dia] = suma_ml_dia;
        suma_ml_dia = 0;
    }
    promedio_mensual = suma_ml_mes / DIAS;
    printf("Promedio diario mensual = %.2fml\n", promedio_mensual);
    for (indice_dia = 0; indice_dia < DIAS; indice_dia++) {
        if (lluvia_diaria[indice_dia] > promedio_mensual)
            printf("En el dia %i han caido %iml\n", indice_dia+1, lluvia_diaria[indice_dia]);
    }
}

int main() {
    MatrizLluviaMensual matriz = { { 3, 17, 42,  8, 55, 29, 71, 14, 63,  2, 88, 37, 50, 11, 76, 23, 45, 99,  6, 31, 58, 84, 19, 40 },
    { 22, 66,  1, 48, 93, 15, 70, 36, 81,  4, 57, 28, 43, 90, 12, 74, 35, 67, 20, 53, 87, 10, 79, 26 },
    { 46, 13, 82, 59,  7, 95, 30, 68, 21, 85, 44,  9, 72, 38, 61, 16, 97, 25, 54, 41, 78,  5, 92, 33 },
    { 69, 24, 51, 86,  3, 62, 18, 94, 47, 11, 73, 56, 27, 83, 39, 64, 17, 48, 91,  8, 35, 77, 22, 60 },
    { 15, 88, 34, 71, 52, 19, 96, 28, 65,  6, 80, 41, 14, 57, 32, 75,  2, 89, 46, 23, 70, 13, 98, 37 },
    { 53, 10, 77, 44, 87, 21, 58,  1, 84, 39, 66, 18, 95, 49, 26, 83, 40, 15, 72, 55,  9, 62, 30, 76 },
    { 28, 91, 16, 63, 30, 74,  5, 50, 97, 24, 43, 88, 11, 67, 20, 53, 36, 81, 14, 59, 85,  3, 48, 94 },
    { 41, 57, 22, 79,  8, 45, 92, 17, 60, 33, 76, 12, 69, 34, 87, 29, 56, 23, 66, 99,  7, 52, 18, 83 },
    { 64,  4, 98, 31, 68, 10, 55, 26, 73, 47, 16, 91, 38, 80, 23, 61,  1, 44, 77, 32, 57, 20, 89, 25 },
    { 37, 74, 20, 85, 42,  6, 81, 63, 18, 95, 28, 52, 77, 15, 48, 34, 70,  3, 93, 24, 41, 67, 12, 58 },
    { 80, 19, 56, 11, 99, 27, 44, 90, 35, 72,  2, 65, 40, 58, 25, 92, 17, 83, 50, 13, 86, 39, 74, 21 },
    {  6, 43, 97, 38, 23, 61, 14, 78, 33, 54, 89, 20, 75, 42,  9, 66, 31, 57, 22, 85, 48, 11, 96, 29 },
    { 62, 18, 75, 49, 16, 84, 39,  7, 53, 86, 22, 47, 13, 98, 31, 55, 10, 77, 64,  2, 90, 26, 43, 68 },
    { 25, 93, 12, 67, 32, 57, 21, 46, 70,  9, 83, 30, 61, 44, 78, 19, 52, 37, 95, 60, 17, 73, 35, 50 },
    { 84,  8, 47, 24, 91, 15, 60, 82,  3, 40, 75, 13, 66, 29, 53, 88,  6, 69, 26, 47, 80, 15, 98, 32 },
    { 39, 76, 28, 55, 10, 72, 43, 19, 87, 26, 58, 97, 35, 62,  4, 81, 24, 45, 11, 94, 38, 65, 20, 77 },
    { 51, 14, 90, 37, 64,  1, 88, 52, 23, 66, 15, 79, 42, 18, 95, 33, 73, 28, 58, 16, 83,  7, 55, 41 },
    { 17, 82, 45,  9, 76, 30, 53, 68,  6, 91, 24, 61, 38, 86, 13, 59, 22, 97, 34, 71,  5, 89, 44, 62 },
    { 73, 26, 69, 43, 18, 95, 38, 11, 77, 50, 32, 85,  7, 54, 70, 27, 46, 13, 88, 25, 60, 37, 81, 19 },
    {  2, 58, 33, 96, 21, 44, 79, 25, 56,  3, 92, 17, 80, 47, 11, 75, 50, 61,  8, 43, 97, 28, 64, 14 },
    { 87, 36, 71, 15, 62, 28, 66,  4, 45, 83, 30, 53, 21, 96, 39, 68, 14, 79, 42, 55,  1, 76, 18, 90 },
    { 23, 68, 10, 84, 47, 70, 17, 92, 38, 67, 14, 49, 78, 25, 57, 32, 85,  9, 63, 31, 74, 49, 10, 53 },
    { 60, 15, 88, 27, 73,  5, 54, 31, 99, 22, 71, 36, 63, 16, 82,  8, 41, 94, 19, 76, 29, 56, 88, 35 },
    { 48,  1, 50, 79, 34, 92, 23, 71, 16, 60, 87, 29, 55, 40, 18, 96, 35, 68, 28, 12, 91, 22, 67, 75 },
    { 11, 77, 44, 20, 67, 13, 86, 40, 29, 74,  8, 63, 45, 91, 24, 72, 49, 30, 84, 53, 16, 95, 42, 26 },
    { 94, 31, 16, 53, 80, 37, 59, 12, 88, 43, 20, 76, 33, 68,  5, 51, 90, 22, 47, 69,  3, 61, 32, 84 },
    { 38, 55, 92, 24, 41, 58,  9, 95, 30, 17, 82, 48, 10, 73, 56, 15, 63, 38, 75, 20, 44, 87,  6, 71 },
    { 19, 86, 61,  7, 74, 22, 83, 48, 13, 55, 94, 27, 70, 37,  4, 88, 25, 57, 10, 92, 33, 66, 50, 15 },
    { 75, 42,  3, 90, 35, 69, 16, 64, 28, 79, 11, 96, 23, 50, 84, 42, 31, 76,  8, 65, 28, 13, 93, 47 },
    { 32, 67, 26, 47, 11, 97, 45, 22, 75, 38, 60, 19, 85, 31, 64,  7, 95, 48, 53, 84, 17, 40, 73, 59 } };
    
    ejercicio_3(matriz);

    return 0;
}
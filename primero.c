/*
Escribir una funcion en C que reciba como parametro un numero entero y
devuelva al modulo invocante los siguientes valores:
- El resultado de multiplicar sus digitos pares y
- La cantidad de digitos que cumplieron la condicion y fueron procesados.

Ejemplo:
25831

los digitos pares son 2 y 8
La funcion devuelve 16 y 2 (2*8=16) (Digitos que cumplen: 2)

IMPORTANTE: NO UTILIZAR ARREGLOS
*/

#include <stdio.h>

void multiplicarPares(int numero, int *cant_pares, int *multiplos) {
    (*multiplos) = 1;
    (*cant_pares) = 0;
    int aux = numero;

    while (numero > 0) { // 25831
        aux %= 10; // 1
        if( aux % 2 == 0) {
            (*multiplos) *= aux;
            (*cant_pares)++;
        }
        numero /= 10; // 2583
        aux = numero;
    }
}


int main() {
    int pares, multiplos;
    int numero = 35331;

    multiplicarPares(numero, &pares, &multiplos);

    // La cantidad de digitos que cumplieron la condicion y fueron procesados
    printf("Cantidad de digitos que cumplieron: %i\n", pares);

    // El resultado de multiplicar sus digitos pares
    if (multiplos != 1) // La variable multiplos nunca fue modificada porque no encontró ningún par
        printf("Multiplicacion de los digitos que cumplieron: %i\n", multiplos);
    else
        printf("Multiplicacion de los digitos que cumplieron: %i\n", multiplos-1);
    return 0;
}
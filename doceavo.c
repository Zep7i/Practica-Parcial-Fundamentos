/*
Escribí un programa que pida números enteros positivos hasta que se ingrese 0. 
Al terminar, tiene que informar cuál fue el número con más dígitos y cuántos dígitos tenía.
*/

#include <stdio.h>

int ContadorDigitos(unsigned int numero) {
    int lon=0;
    while (numero > 0) {
        numero = numero / 10;
        lon++;
    }
    return lon;
}

void MasDigitos() {
    unsigned int numero, mayor_digitos;
    printf("Ingrese un numero entero positivo (0 para terminar): ");
    scanf(" %i", &numero);
    mayor_digitos = numero;
    while (numero != 0) {
        if (ContadorDigitos(numero) > ContadorDigitos(mayor_digitos))
            mayor_digitos = numero;
        printf("Ingrese un numero entero positivo (0 para terminar): ");
        scanf(" %i", &numero);
    }
    if (mayor_digitos != 0)
        printf("El numero con mas digitos era el %i con una cantidad de %i digitos.\n", mayor_digitos, ContadorDigitos(mayor_digitos));
}

int main() {
    MasDigitos();
    return 0;
}
/*
funcion que reciba un numero entero n y que devuelva al mod. invocante
el enesimo termino de la sucesion geometrica de razon. 
(El primer termino es 1)

si n=5 y razon=2 entonces
la sucesion es 1 2 4 8 16 (5 terminos)
la funcion devolverá 16
*/

#include <stdio.h>

int SucGeom(int n, int razon, int *n_termino) {
    int contador;
    (*n_termino) = 1;
    for (contador = 1; contador < n; contador++)
        (*n_termino) *= razon; 

    return (*n_termino);
}

int main() {
    int n_term;

    SucGeom(3, 2, &n_term);
    printf("Enesimo termino: %i", n_term);

    return 0;
}
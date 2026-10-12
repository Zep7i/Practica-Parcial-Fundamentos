/*
Dadas las siguientes declaraciones de constantes y tipos:
#define MAX 500
typdef int Tvector[MAX];

Desarrollar una funcion en lenguaje C que reciba como parametros un vector de tipo Tvector
ya cargado y su maximo logico, que devuelva al modulo invocante:
- El indice en el vector del primer numero negativo presente (Devolver -1 en caso de no haber ninguno)
- Una variable booleana que indique si contiene al menos un numero par mayor que 100

Nota: Resolver recorriendo una unica vez el vector.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 500
typedef int Tvector[MAX];

void Analisis_Vector(Tvector vec, int ml, int *ind_negativo, bool *ParMayor100) {
    int contador = 0;
    (*ind_negativo) = -1;
    (*ParMayor100) = false;
    
    while ( (*ind_negativo) == -1 && contador < ml) {
        if (vec[contador] % 2 == 0 && vec[contador] > 100)
            (*ParMayor100) = true;
        if (vec[contador] < 0)
            (*ind_negativo) = contador;
        contador++;
    }
}

int main() {
    Tvector vec = {-1, 3, 1, 5, 3, 0};
    int ml = 6;
    int ind_neg;
    bool parmayor100;

    Analisis_Vector(vec, ml, &ind_neg, &parmayor100);

    if (ind_neg != -1)
        printf("El indice del primer numero negativo es: %i\n", ind_neg);
    else
        printf("No se encontraron numeros negativos en el vector.\n");

    if (parmayor100 == true)
        printf("Existe almenos un numero par mayor que 100!\n");
    
    return 0;
}
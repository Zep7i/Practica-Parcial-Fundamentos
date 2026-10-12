/*
INVERTIR EL VECTOR
*/

#include <stdio.h>
#define MAX 2

int main() {
    float VEC[MAX] = {107.00, 23.00};
    
    // Mostrar el vector
    printf("{ ");
    for(int j=0; j < MAX; j++) {
        printf("%.0f ", VEC[j]);
    }
    printf("}\n");

    // Reemplazo
    for (int i=0; i < MAX/2; i++) {
        float elemento_reemplazo = VEC[(MAX-1)-i];
        VEC[(MAX-1)-i] = VEC[i];
        VEC[i] = elemento_reemplazo;
    }

    // Mostrar el vector invertido
    printf("{ ");
    for(int j=0; j < MAX; j++) {
        printf("%.0f ", VEC[j]);
    }
    printf("}");

    return 0;
}
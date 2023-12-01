#include <stdio.h>
#include <stdlib.h>
#include "studio.h"

int sumarEnteros(int a, int b) {
    return a + b;
}

void concatenarCaracteres() {
    char cadena[100];
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);
    printf("Cadena ingresada: %s\n", cadena);
}
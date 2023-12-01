#include <stdio.h>
#include "histograma.h"

void ObtenerCantidadesDePalabrasPorLongitud(FILE *flujo, unsigned longitudes[], int size) {
    unsigned cantidadDeCaracteres = 0;
    int c;
    bucle: 
    for (;(c = getc(flujo)) != EOF;) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (c != ' ' || c != '\n' || c != '\t') 
                goto in;
        } else 
            goto out;
    }
    if(c != ' ' || c != '\n' || c != '\t'){ //ultima palabra
        longitudes[cantidadDeCaracteres-1]++;
    }
    return;

in: 
    longitudes[cantidadDeCaracteres-1]++;
    cantidadDeCaracteres = 0;
    goto bucle;
out:
    cantidadDeCaracteres++;
    goto bucle;
}



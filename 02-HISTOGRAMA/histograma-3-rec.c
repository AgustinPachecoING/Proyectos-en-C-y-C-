#include <stdio.h>
#include "histograma.h"

void stateIn(unsigned histograma[], unsigned, FILE *flujoaux);
void stateOut(unsigned histograma[], unsigned,FILE *flujoaux);

void ObtenerCantidadesDePalabrasPorLongitud(FILE *flujo, unsigned longitudes[], int size) {
    unsigned cantidadDeCaracteres = 0;
    stateOut(longitudes, cantidadDeCaracteres,flujo);
}

void stateIn(unsigned histograma[], unsigned cantidadDeCaracteres, FILE * flujoaux) {
    int c = getc(flujoaux);
    if (c == EOF) {
        histograma[cantidadDeCaracteres - 1]++;
        return;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
        histograma[cantidadDeCaracteres - 1]++;
        stateOut(histograma, 0, flujoaux);
    } else {
        cantidadDeCaracteres++;
        stateIn(histograma, cantidadDeCaracteres, flujoaux);
    }
}

void stateOut(unsigned histograma[], unsigned cantidadDeCaracteres, FILE * flujoaux) {
    int c = getc(flujoaux);
    if (c == EOF) {
        return;
    }
    if (c == ' ' || c == '\n' || c == '\t') 
        stateOut(histograma, cantidadDeCaracteres, flujoaux);
     else {
        cantidadDeCaracteres = 1;
        stateIn(histograma, cantidadDeCaracteres, flujoaux);
    }
}

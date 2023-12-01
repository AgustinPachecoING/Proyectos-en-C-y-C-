#include <stdio.h>
//#include <string.h>
#include "histograma.h"


void ObtenerCantidadesDePalabrasPorLongitud(FILE *flujo, unsigned longitudes[], int size) {
    State estado = OUT;
    int longitudPalabra = 0;

    for (int c; (c = fgetc(flujo)) != EOF;) {
        switch (estado) {
            case OUT:
                if (c != ' ' && c != '\n' && c != '\t' && c != '\0') {
                    estado = IN;
                    longitudPalabra = 1;
                }
                break;
            case IN:
                if (c == ' ' || c == '\n' || c == '\t' || c == '\0') {
                    estado = OUT;
                    longitudes[longitudPalabra-1]++;
                } else {
                      longitudPalabra++;
                }
                break;
        }
    }
    if(estado == IN){ //ultima palabra
        longitudes[longitudPalabra-1]++;
    }
}
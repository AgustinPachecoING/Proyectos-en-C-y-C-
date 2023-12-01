#include <stdio.h>
#include <stdbool.h>
#include "histograma.h"
//#include "Graficador.h"

#define condicion ((c == ' ') || (c == '\n') || (c == '\t') || (c == '\0'))

void ObtenerCantidadesDePalabrasPorLongitud(FILE *flujo, unsigned longitudes[], int size){

    bool estado = false;
    int longitudPalabra = 0;
    int c;

    for(c; (c = fgetc(flujo)) != EOF;){

        if(!estado){
            if(!condicion){
                estado = true;
                longitudPalabra = 1;
            }
        }
        else if(estado=true){
            if(condicion){
                estado = false;
                longitudes[longitudPalabra-1]++;
            }
            else{
                longitudPalabra++;
            }
        }
    }
    longitudes[longitudPalabra-1]++;
}
#include <stdio.h> //FILE
#include "Graficador.h"

void DibujarHistograma(FILE *flujo, const unsigned datos[], size_t tamanio, Orientacion orien, char caracter) {
    if (orien == vertical) {
        // Dibujar histograma vertical
        int maximo = 0;

        // Encontrar el valor máximo de los datos
        for (int i = 0; i < tamanio; i++) {
            if (datos[i] > maximo) {
                maximo = datos[i];
            }
        }

       for (int nivel = maximo; nivel > 0; nivel--) {
        for (int i = 0; i < tamanio; i++) {
                if (datos[i] >= nivel) {
                    fprintf(flujo,"%c  ", caracter);
                } else {
                    fprintf(flujo,"   ");
            }
            }
        fprintf(flujo,"\n");
        }

        // Imprimir etiquetas de las barras inferiores
        for (int i = 0; i < tamanio; i++) {
            fprintf(flujo,"%d  ", i+1);
        }
        fprintf(flujo,"\n");
    } else {
        // Dibujar histograma horizontal
        for (int i = 0; i < tamanio; i++) {
            fprintf(flujo,"%d: ",i+1);
            for (int j = 0; j < datos[i]; j++) {
                fprintf(flujo,"%c",caracter);
            }
            fprintf(flujo,"\n");
        }
    }
}
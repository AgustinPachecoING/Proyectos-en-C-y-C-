#include <stdio.h> //stdin y stdout
#include "Graficador.h" //DibujarHistograma y horizontal
#include "Graficador.h"
#include "histograma.h" //ObtenerCantidadesDePalabrasPorLongitud
#include <time.h>
#define CANTIDAD_CONTADORES 10

int main(void){
    unsigned longitudes[CANTIDAD_CONTADORES]= {0}; //TO DO
    clock_t inicio, fin;
    double tiempo_ms;
    // FILE *pruebas = fopen("pruebas.txt", "r");
    // if (pruebas == NULL) {
    //     printf("Error al abrir el archivo de pruebas.\n");
    //     return 1;
    // }
    inicio = clock();
    ObtenerCantidadesDePalabrasPorLongitud(stdin,longitudes,CANTIDAD_CONTADORES);
    fin = clock();
    tiempo_ms = (double)(fin - inicio) * 1000 / CLOCKS_PER_SEC;
    printf("Tiempo de procesamiento: %lf milisegundos\n", tiempo_ms);
    // fclose(pruebas);

    // Abrir el archivo para escribir el resultado obtenido
    FILE *resultado = fopen("resultado_obtenido.txt", "w");
    if (resultado == NULL) {
        printf("Error al abrir el archivo de resultado obtenido.\n");
        return 1;
    }
    DibujarHistograma(resultado, longitudes,CANTIDAD_CONTADORES,horizontal,'*'); //TO DO - Cantidad de contado
    fclose(resultado);
}
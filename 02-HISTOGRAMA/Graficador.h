#ifndef GraficadorIncluido
#define GraficadorIncluido
#include <stddef.h>
/**
 * @brief Imprime un histograma de acuerdo a los parametros recibidos.
 *
 * @param datos Los datos a imprimir en el histograma
 * @param tamanio Lla longitud del array de datos
 * @param vertical indica el modo de orientacion del histograma
 * @param separador El caracter separador que se usa para dibujar el histograma
 */
typedef enum { horizontal, vertical} Orientacion;
void DibujarHistograma(FILE *flujo, const unsigned *datos, size_t tamanio, Orientacion or, char caracter);
#endif

/**
 * @brief Obtiene las cantidades de las longitudes de palabras
 *
 * @param texto el texto con las palabras a contar longitudes
 * @param longitudes un arreglo con todas las cantidades de palabras por longitud
 */
typedef enum {
  OUT,
  IN
} State;
void ObtenerCantidadesDePalabrasPorLongitud(FILE *flujo, unsigned longitudes[], int size);
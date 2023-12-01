#include <stdio.h>
#include <assert.h>
#include <stdbool.h> 
#include <string.h>

#define MAX_WORD_LENGTH 10

void compareHistograms(unsigned histogram1[], unsigned histogram2[], int size) {
    bool sonIguales = true;

    for (int i = 0; i < size-1; i++) {
        if (histogram1[i] != histogram2[i]) {
            sonIguales = false;
            printf("Diferencia en la posicion %d. Valor en histogram1: %d, Valor en histogram2: %d\n", i, histogram1[i], histogram2[i]);
        }
    }
    assert(sonIguales);
}

void getHistogramFromFile(const char *filename, unsigned histogram[]) {
    char linea[256];
    int numero;

    FILE *archivo = fopen(filename, "r");
        if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo)) {
        if (sscanf(linea, "%d: %*s", &numero) == 1) {
            char *asteriscos = strchr(linea, '*');
            if (asteriscos != NULL) {
                int posicion = numero - 1;
                while (*asteriscos) {
                    asteriscos++;
                    histogram[posicion]++;
                }
            }
        }
    }

    fclose(archivo);
}

int main() {
    unsigned expectedHistogram[MAX_WORD_LENGTH] = {0};
    getHistogramFromFile("resultado_esperado.txt", expectedHistogram);

    unsigned histogram[MAX_WORD_LENGTH] = {0};
    getHistogramFromFile("resultado_obtenido.txt", histogram);

    compareHistograms(histogram, expectedHistogram, MAX_WORD_LENGTH);

    printf("Test PASSED: El histograma obtenido coincide con el resultado esperado.\n");

    return 0;
}
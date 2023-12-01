CC = gcc
PRUEBA = pruebas.txt

run1: main.o histograma-1-enum-switch.o Graficador.o
	$(CC) main.o histograma-1-enum-switch.o Graficador.o -o longitudes
	./longitudes.exe < $(PRUEBA)

run2: main.o histograma-2-goto.o Graficador.o
	$(CC) main.o histograma-2-goto.o Graficador.o -o longitudes
	./longitudes.exe < $(PRUEBA)
run3: main.o histograma-3-rec.o Graficador.o
	$(CC) main.o histograma-3-rec.o Graficador.o -o longitudes
	./longitudes.exe < $(PRUEBA)
run4: main.o histograma-4-bool.o Graficador.o
	$(CC) main.o histograma-4-bool.o Graficador.o -o longitudes
	./longitudes.exe < $(PRUEBA)   

main.o: main.c histograma.h Graficador.h
	$(CC) -c main.c -o main.o

histograma-1-enum-switch.o: histograma-1-enum-switch.c histograma.h
	$(CC) -c histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o: histograma-2-goto.c histograma.h
	$(CC) -c histograma-2-goto.c -o histograma-2-goto.o
histograma-3-rec.o: histograma-3-rec.c histograma.h
	$(CC) -c histograma-3-rec.c -o histograma-3-rec.o
histograma-4-bool.o: histograma-4-bool.c histograma.h
	$(CC) -c histograma-4-bool.c -o histograma-4-bool.o

Graficador.o: Graficador.c Graficador.h
	$(CC) -c Graficador.c -o Graficador.o

clean:
	rm -f Graficador.o histograma-1-enum-switch.o  main.o longitudes.exe resultado_obtenido.txt test.exe histograma-2-goto.o histograma-4-bool.o histograma-3-rec.o

test: longitudes test.c
	$(CC)  test.c -o test
	./test.exe

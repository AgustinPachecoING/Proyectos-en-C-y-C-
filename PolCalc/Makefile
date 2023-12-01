CC = gcc
EXPRESIONES = expresiones.txt

Calculator.o : Calculator.c StackOfDoublesModule.h Scanner.h
	$(CC) -Wall -c Calculator.c -o Calculator.o

Scanner.o : Scanner.c Scanner.h
	$(CC) -Wall -c Scanner.c -o Scanner.o

StackOfDoublesModule.o : StackOfDoublesModule.c StackOfDoublesModule.h
	$(CC) -Wall -c StackOfDoublesModule.c -o StackOfDoublesModule.o

run : Calculator.o StackOfDoublesModule.o Scanner.o
	$(CC) -Wall Calculator.o Scanner.o StackOfDoublesModule.o -o resultados
		./resultados.exe < $(EXPRESIONES)

clean : 
	rm -f Scanner.o StackOfDoublesModule.o  Calculator.o resultados.exe

# --------------------------------
#CC = gcc
#EXPRESIONES = expresiones.txt

#main.o : main.c StackOfDoublesModule.h
#	$(CC) -c main.c -o main.o

#Scanner.o : Scanner.c Scanner.h
#	$(CC) -c Scanner.c -o Scanner.o

#StackOfDoublesModule.o : StackOfDoublesModule.c StackOfDoublesModule.histograma
#	$(CC) -c StackOfDoublesModule.c -o StackOfDoublesModule.o

#run : main.o StackOfDoublesModule.o scanner.o
#	$(CC) main.o StackOfDoublesModule.o scanner.o -o resultados
#		./resultado.exe < $(EXPRESIONES)

#clean : 
#	rm -f Scanner.o StackOfDoublesModule.o  main.o resultado.exe


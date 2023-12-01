CC = gcc
EXPRESIONES = expresiones.txt


CalculatorBison.o : y.tab.c y.tab.h
	$(CC) -Wall -c y.tab.c -o CalculatorBison.o

Scanner.o : lex.yy.c y.tab.h
	$(CC) -Wall -c lex.yy.c -o Scanner.o


run : CalculatorBison.o Scanner.o
	$(CC) -Wall CalculatorBison.o Scanner.o -o resultados
		./resultados.exe < $(EXPRESIONES)

bis: 
	bison -yd Bison.y
fl: 
	flex reglas.l

reset: 
	rm -f lex.yy.c y.tab.c y.tab.h

clean : 
	rm -f Scanner.o CalculatorBison.o  resultados.exe 

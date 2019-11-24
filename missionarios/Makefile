all: main clean

main:  estado.o fila.o main.o
	gcc main.o estado.o fila.o -o main

main.o: main.c 
	gcc main.c -c -Wall -pedantic

estado.o: implementacoes/estado.c cabecalhos/estado.h
	gcc -o estado.o implementacoes/estado.c -c -Wall -pedantic

fila.o: implementacoes/fila.c cabecalhos/estado.h cabecalhos/fila.h
	gcc -o fila.o implementacoes/fila.c -c -Wall -pedantic

clean: 
	rm -rf *.o *~
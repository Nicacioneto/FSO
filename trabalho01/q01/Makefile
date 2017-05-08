system: clean entradaVertices.o main.o operacoes.o
	gcc main.o entradaVertices.o operacoes.o -lm -o run
	rm -rf *.o
	./run

main.o: main.c
	gcc -c main.c -o main.o -lm

entradaVertices.o: entradaVertices.c
	gcc -c entradaVertices.c -o entradaVertices.o -lm

operacoes.o: operacoes.c
	gcc -c operacoes.c -o operacoes.o -lm
clean:
	rm -rf *.o

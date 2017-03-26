ordenaVetor: main.o ordenaVetor.o vetor.o
	gcc $(CFLAGS) -o ordenaVetor main.o ordenaVetor.o vetor.o

main.o: main.c vetor.h ordenaVetor.h
	gcc $(CFLAGS) -c main.c

vetor.o: vetor.c
	gcc $(CFLAGS) -c vetor.c

ordenaVetor.o: ordenaVetor.c vetor.h
	gcc $(CFLAGS) -c ordenaVetor.c

clean:
	rm -f *.o ordenaVetor
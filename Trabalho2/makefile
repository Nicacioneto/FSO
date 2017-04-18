comunication: file.o comunication.o
	gcc $(CFLAGS) -o comunication file.o comunication.o

comunication.o: comunication.c file.h
	gcc $(CFLAGS) -c comunication.c

file.o: file.c
	gcc $(CFLAGS) -c file.c

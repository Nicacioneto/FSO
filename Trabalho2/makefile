comunication: file.o comunication.o active_process.o
	gcc $(CFLAGS) -o comunication file.o comunication.o active_process.o

comunication.o: comunication.c file.h
	gcc $(CFLAGS) -c comunication.c

file.o: file.c
	gcc $(CFLAGS) -c file.c

active_process.o: active_process.c
	gcc $(CFLAGS) -c active_process.c

clean:
		rm -f *.o
		rm -f *.txt
		rm -f *.out

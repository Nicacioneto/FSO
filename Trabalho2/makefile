comunication: writers.o comunication.o active_process.o time_functions.o 
	gcc $(CFLAGS) -o comunication writers.o comunication.o active_process.o time_functions.o

comunication.o: comunication.c writers.h
	gcc $(CFLAGS) -c comunication.c

writers.o: writers.c
	gcc $(CFLAGS) -c writers.c

time_functions.o: time_functions.c
	gcc $(CFLAGS) -c time_functions.c

active_process.o: active_process.c writers.h time_functions.h
	gcc $(CFLAGS) -c active_process.c

clean:
		rm -f *.o
		rm -f *.txt
		rm -f *.out

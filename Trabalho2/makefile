main: writers.o main.o active_process.o lazy_child.o time_functions.o
	gcc $(CFLAGS) -o main writers.o main.o active_process.o lazy_child.o time_functions.o

main.o: main.c writers.h
	gcc $(CFLAGS) -c main.c

writers.o: writers.c
	gcc $(CFLAGS) -c writers.c

time_functions.o: time_functions.c
	gcc $(CFLAGS) -c time_functions.c

active_process.o: active_process.c children.h time_functions.h
	gcc $(CFLAGS) -c active_process.c

lazy_child.o: lazy_child.c children.h time_functions.h
	gcc $(CFLAGS) -c lazy_child.c

clean:
	rm -f *.o
	rm -f *.txt

main: main.o libseno.so
	gcc $(CFLAGS) -o main main.o -L. -lseno

main.o: main.c libseno.so
	gcc $(CFLAGS) -c main.c

libseno.so: libseno.c
	gcc $(CFLAGS) -shared -fPIC libseno.c -o libseno.so

clean:
		rm -f *.o

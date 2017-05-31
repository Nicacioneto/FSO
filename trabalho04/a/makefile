main: main.o libseno.a
	 gcc -o main main.o -L. -lseno -Wl,-rpath,./

main.o: main.c
	gcc -c main.c

libseno.a: libseno.o
	ar cr libseno.a libseno.o

libseno.o: libseno.c
	gcc -fPIC -o libseno.o -c libseno.c

clean:
		rm -f *.o
		rm -f *.a
		rm main

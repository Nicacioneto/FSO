trabalho_04: main.o libseno.so
	 gcc -o trabalho_04 main.o -L. -lseno -Wl,-rpath,./

main.o: main.c
	gcc -c main.c

libseno.so: libseno.o
	gcc -shared -fPIC -o libseno.so libseno.o

libseno.o: ../libseno.c
	gcc -fPIC -o libseno.o -c ../libseno.c

clean:
		rm -f *.o *.so trabalho_04

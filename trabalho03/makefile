main: main.o producer_thread.o vector_information.o consumer_thread.o controller_thread.o
	gcc $(CFLAGS) -o main main.o producer_thread.o vector_information.o consumer_thread.o controller_thread.o -lpthread

main.o: main.c producer_thread.h vector_information.h
	gcc $(CFLAGS) -c main.c -lpthread

producer_thread.o: producer_thread.c vector_information.h
	gcc $(CFLAGS) -c producer_thread.c

consumer_thread.o: consumer_thread.c vector_information.h
	gcc $(CFLAGS) -c consumer_thread.c

controller_thread.o: controller_thread.c vector_information.h
	gcc $(CFLAGS) -c controller_thread.c

vector_information.o: vector_information.c
	gcc $(CFLAGS) -c vector_information.c

clean:
		rm -f *.o

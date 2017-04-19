#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  char message[100];
  int file_fifo = open(argv[1], "r");
  read(file_fifo, message, 100);
  printf("message = %s\n", message);
  return 0;
}

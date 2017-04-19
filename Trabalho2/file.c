#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void writer(const char* message, FILE* stream){
  printf("Writing: %s\n", message);
  fprintf(stream, "%s\n", message);
  fflush(stream);
}

void reader(FILE* stream){
  char buffer[1024];
  FILE* output = fopen("output.txt", "w");

  while(!feof(stream) && !ferror(stream)&& fgets(buffer, sizeof(buffer), stream) != NULL) {
  	writer(buffer, output);
  }

  close(output);
}

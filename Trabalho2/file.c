#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void writer(const char* message, FILE* stream){
  fprintf(stream, "%s\n", message);
  fflush(stream);
}

void reader(FILE* stream){
  char buffer[1024];

  while(!feof(stream)
  && !ferror(stream)
  && fgets(buffer, sizeof(buffer), stream) != NULL)
  fputs(buffer, stdout);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "writers.h"

void writer_pipe_active_process(const char* message, struct timeval *time_elapsed, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do usuario: <%s>\n", time_elapsed->tv_sec, time_elapsed->tv_usec, i, message);
  fflush(pipe);
}

void writer_pipe_lazy_child(struct timeval *time_elapsed, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do filho dorminhoco\n", time_elapsed->tv_sec, time_elapsed->tv_usec, i);
  fflush(pipe);
}

void get_message_pipe_and_write_file(FILE* pipe) {
  char buffer[1024];
  FILE* output = fopen("output.txt", "w");

  while(!feof(pipe) && !ferror(pipe)&& fgets(buffer, sizeof(buffer), pipe) != NULL) {
  	fprintf(output, "%s\n", buffer);
    fflush(output);
  }

  close(output);
}

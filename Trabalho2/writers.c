#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "writers.h"

void writer_pipe_active_process(const char* message, struct timeval *time_elapsed, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do usuario: <%s>\n", time_elapsed->tv_sec, time_elapsed->tv_usec, i, message);
  fflush(pipe);
  return;
}

void writer_pipe_lazy_child(struct timeval *time_elapsed, FILE* pipe, int i) {
  fprintf(pipe, "0:%02ld.%03ld: Mensagem do %02d do filho dorminhoco\n", time_elapsed->tv_sec, time_elapsed->tv_usec, i);
  fflush(pipe);
}

void get_message_pipe_and_write_file(FILE* pipe, FILE *output, struct timeval *time_begin) {
  char buffer[1024];

  struct timeval time_end, time_elapsed;
  gettimeofday(&time_end, NULL);

  calcute_time_elapsed(time_begin, &time_end, &time_elapsed);

 	if(!feof(pipe) && !ferror(pipe) && fgets(buffer, sizeof(buffer), pipe) != NULL){
    fprintf(output, "0:%02ld.%03ld: %s\n",time_elapsed.tv_sec, time_elapsed.tv_usec, buffer);
    fflush(output);
  }

}

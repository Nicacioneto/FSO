#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "writers.h"
#include "active_process.h"



int main(){
  int active_process_pipe[2];
  pipe (active_process_pipe);

  pid_t active_process;
  active_process = fork();

  /* Active child process */
  if (active_process == (pid_t)0) {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    execute_active_process(active_process_pipe, &time_begin);
  }

  /* Parent process */
  else {
    close (active_process_pipe[1]); // close write

    FILE* pipe;
    pipe = fdopen (active_process_pipe[0], "r");
    get_message_pipe_and_write_file (pipe);

    close(active_process_pipe[0]);
  }

  return 0;
}

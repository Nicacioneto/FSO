#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "writers.h"
#include "childs.h"



int main(){
  int active_process_pipe[2];
  pipe (active_process_pipe);

  pid_t active_process;
  active_process = fork();

  int lazy_child_pipe[2];
  pipe (lazy_child_pipe);

  pid_t lazy_child;
  lazy_child = fork();

  /* Active child process */
  if (active_process == (pid_t)0) {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    execute_active_process(active_process_pipe, &time_begin);
  }

  /* Active child process */
  else if (lazy_child == (pid_t)0) {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    execute_lazy_child(lazy_child_pipe, &time_begin);
  }

  /* Parent process */
  else {
    close (active_process_pipe[1]);
    close (lazy_child_pipe[1]);

    FILE* pipe_active_child;
    pipe_active_child = fdopen (active_process_pipe[0], "r");

    FILE* pipe_lazy_child;
    pipe_lazy_child = fdopen (lazy_child_pipe[0], "r");

    get_message_pipe_and_write_file (pipe_lazy_child);

    close(active_process_pipe[0]);
  }

  return 0;
}

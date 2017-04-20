#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#include "writers.h"
#include "children.h"

#define TIME_MAX 30

pid_t active_process = -1;
pid_t lazy_child = -1;

void finish_program(int signal) {
  int status;
  kill(active_process, SIGTERM);
  kill(lazy_child, SIGTERM);

  exit(0);
}

int main(){
  int active_process_pipe[2];
  pipe (active_process_pipe);

  active_process = fork();

  int lazy_child_pipe[2];
  pipe (lazy_child_pipe);

  lazy_child = fork();

  /* Active child process */
  if (active_process == (pid_t)0) {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    execute_active_process(active_process_pipe, &time_begin);
  }

  /* Lazy child process */
  else if (lazy_child == (pid_t)0) {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    execute_lazy_child(lazy_child_pipe, &time_begin);
  }

  /* Parent process */
  else {
    struct timeval time_begin;
    gettimeofday(&time_begin, NULL);

    signal(SIGALRM, finish_program);
    alarm(TIME_MAX);

    close (active_process_pipe[1]);
    close (lazy_child_pipe[1]);

    dup2 (active_process_pipe[0], STDIN_FILENO);
    dup2 (lazy_child_pipe[0], STDIN_FILENO);

    FILE* output = fopen("output.txt", "w");

    FILE* pipe_active_child;
    pipe_active_child = fdopen (active_process_pipe[0], "r");

    FILE* pipe_lazy_child;
    pipe_lazy_child = fdopen (lazy_child_pipe[0], "r");
    
    fd_set fds;
    FD_ZERO(&fds); // Clear FD set for select
    
    while(1){

      FD_SET(active_process_pipe[0], &fds);
      FD_SET(lazy_child_pipe[0], &fds);

      select(FD_SETSIZE, &fds, NULL, NULL, 0);
      

      if (FD_ISSET(active_process_pipe[0], &fds)) {
        get_message_pipe_and_write_file (pipe_active_child, output, &time_begin);
      }

      if (FD_ISSET(lazy_child_pipe[0], &fds)) {
        get_message_pipe_and_write_file (pipe_lazy_child, output, &time_begin);
      }

    }

      printf("finishing...\n");
    close(active_process_pipe[0]);
    close(lazy_child_pipe[0]);
    fclose(output);
  }

  return 0;
}

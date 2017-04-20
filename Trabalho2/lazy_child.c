#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "children.h"
#include "writers.h"
#include "time_functions.h"

void execute_lazy_child(pid_t lazy_child_pipe[2], struct timeval *time_begin) {
  close (lazy_child_pipe[0]); // close read

  FILE* pipe;
  pipe = fdopen (lazy_child_pipe[1], "w");

  int i = 1;
  while(1) {
    int random = rand() % 3;
    sleep (random);

    struct timeval time_end, time_elapsed;
    gettimeofday(&time_end, NULL);

    calcute_time_elapsed(time_begin, &time_end, &time_elapsed);

    writer_pipe_lazy_child(&time_elapsed, pipe, i++);
  }

  close (lazy_child_pipe[1]);
}

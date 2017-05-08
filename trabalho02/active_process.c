#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "children.h"
#include "writers.h"
#include "time_functions.h"

void execute_active_process(pid_t active_process_pipe[2], struct timeval *time_begin) {
  close (active_process_pipe[0]); // close read

  FILE* pipe;
  pipe = fdopen (active_process_pipe[1], "w");

  int i = 1;
  while(1) {
    char message_user[100];
    scanf("%s", message_user);

    struct timeval time_end, time_elapsed;
    gettimeofday(&time_end, NULL);

    calcute_time_elapsed(time_begin, &time_end, &time_elapsed);

    writer_pipe_active_process(message_user, &time_elapsed, pipe, i);
    i++;
  }

  close (active_process_pipe[1]);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "active_process.h"
void execute_active_process(pid_t active_process_pipe[2]) {
  close (active_process_pipe[0]); // close read

  FILE* stream;
  stream = fdopen (active_process_pipe[1], "w");

  while(1) {
    printf("child\n");
    char message[100];
    scanf("%s", message);

    printf("%s\n", message);
    writer(message, stream);
  }

  close (active_process_pipe[1]);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

#include "file.h"
#include "active_process.h"

int main(){
  int active_process_pipe[2];
  pipe (active_process_pipe);

  pid_t active_process;
  active_process = fork();

  /* Active child process */
  if (active_process == (pid_t)0) {
    execute_active_process(active_process_pipe);
  }
  
  /* Parent process */
  else {

    printf("dad\n");
    close (active_process_pipe[1]); // close write
    FILE* stream;
    stream = fdopen (active_process_pipe[0], "r");
    reader (stream);

    close(active_process_pipe[0]);
  }

  return 0;
}

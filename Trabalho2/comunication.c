#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include "file.h"

int main(){
  int active_process_pipe[2];
  pipe (active_process_pipe);

  pid_t active_process;
  active_process = fork();

  /* Active child process */
  if (active_process == (pid_t)0) {
    clock_t start =  clock();

    close (active_process_pipe[0]); // close read
    
    FILE* stream;
    stream = fdopen (active_process_pipe[1], "w");
   
    while(1) {
      char message[100];
      scanf("%s", message);

      clock_t end = clock();
      unsigned long micros = end - start;
      float millis = micros / 1000;
      
      char *full_message;
      sprintf(full_message, "%.3f", millis);
      strcat(full_message, message);

      writer(full_message, stream);
    }

    close (active_process_pipe[1]);
  }
  /* Parent process */
  else {
    close (active_process_pipe[1]); // close write
    FILE* stream;
    stream = fdopen (active_process_pipe[0], "r");
    reader (stream);

    close(active_process_pipe[0]);
  }

  return 0;
}

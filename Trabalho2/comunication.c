#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>



void writer(const char* message, FILE* stream)
{
  fprintf(stream, "%s\n", message);
  fflush(stream);


}

void reader(FILE* stream)
{
  char buffer[1024];

  while(!feof(stream)
  && !ferror(stream)
  && fgets(buffer, sizeof(buffer), stream) != NULL)
  fputs(buffer, stdout);
}


int main()
{
  int fds[2];

  pid_t slow;

  pipe(fds);

  slow = fork();

  if(slow ==(pid_t) 0)
  {
    FILE* stream;

    close(fds[0]);

    char *message = (": Mensagem 01 do filho dorminhoco");

    stream = fopen("output.txt", "wb");

    writer(message, stream);

    close(fds[1]);

  } else {
    FILE* stream;

    stream = fopen("output.txt", "wb");

    close(fds[1]);

    reader(stream);

    close(fds[0]);

    sleep(30);

    kill(getpid(), SIGKILL);

    fclose(stream);

  }
  return 0;


}

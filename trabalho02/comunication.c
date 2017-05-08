#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
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




int main(){
  int pslow[2];
  int pfast[2];
  int random = rand() % 3;
  int index = 0;

  pid_t slow;
  pid_t fast;

  pipe(pslow);

  slow = fork();

  if(slow == 0){

    printf("Slow process\n");

    FILE* stream;

    close(pslow[0]);

    char *message = (": Mensagem 01 do filho dorminhoco");

    stream = fopen("output.txt", "wb");

    writer(message, stream);

    close(pslow[1]);

  } else {
    fast = fork();

    pipe(pfast);

    if(fast == 0){
      printf("Fast process\n");

      FILE* stream;

      close(pfast[0]);

      char *message2 = (": Mensagem 01 do usuario:<>");

      stream = fopen("output.txt", "wb");

      writer(message2, stream);

      close(pfast[1]);
    } else {

      printf("Parent process\n");

      FILE* stream;

      stream = fopen("output.txt", "wb");

      close(pslow[1]);

      close(pfast[1]);

      reader(stream);

      close(pslow[0]);

      close(pfast[0]);

      sleep(3);

      kill(getpid(), SIGKILL);

      fclose(stream);

    }
  }
  return 0;

}

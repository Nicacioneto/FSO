#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t child_pid;

  printf("the main program process ID is %d\n",getpid());
  child_pid = fork();
  if(child_pid != 0) {
    printf("this is the parent process, with id %d\n",getpid());
    printf("the child’s process ID is  %d\n", child_pid);

  }
  else
    printf("this is the child process, with id %d\n", getpid());
  return 0;
}

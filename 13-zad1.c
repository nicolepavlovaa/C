#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
  int pid=fork();
  if(pid==-1)
  {
    perror("Couldn't fork!\n");
    exit(-1);
  }
  else if(pid>0)
  {
    printf("Parent PID is %d and its parent is %d\n", getpid(), getppid());
  }
  else
  {
    wait(10);
    printf("\n");
    printf("Child PID is %d and its parent is %d\n", getpid(), getppid());
  }
  return 0;
}

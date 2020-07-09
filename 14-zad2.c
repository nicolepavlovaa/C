#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int status;
  int pid=fork();
  if(pid==-1)
  {
    perror("Couldnt fork\n");
    exit(-1);
  }
  else if(pid>0)
  {
    //parent
    wait(&status);
    pid=fork();
    if(pid==-1)
    {
      perror("Couldnt fork\n");
      exit(-1);
    }
    else if(pid>0)
    {
      wait(&status);
    }
    else
    {
      if(execvp(argv[2], &argv[2])==-1)
      {
        printf("Couldnt execute 2\n");
        exit(-1);
      }
    }
  }
  else
  {
    if(execlp("grep", "grep", "int", argv[1], (char*)NULL)==-1)
    {
      printf("Couldnt execute 1\n");
      exit(-1);
    }
  }
  return 0;
}

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
    //Parent
    printf("Waiting for child to finish...\n");
    int p1=wait(&status);
    printf("Child pid is %d and finished with exit code %d\n", p1, status);
    if(status!=0)
    {
      exit(-1);
    }
    pid=fork();
    if(pid==-1)
    {
      perror("Couldnt fork\n");
      exit(-1);
    }
    else if(pid > 0)
    {
      printf("Waiting for child to finish...\n");
      int p2=wait(&status);
      printf("Child pid is %d and finished with exit code %d\n",p2, status);
      if(status!=0)
      {
        exit(-1);
      }
    }
    else
    {
      if(execlp(argv[2], argv[2], (char*)NULL)==-1)
      {
        printf("Couldn't execute second command\n");
        exit(-1);
      }
    }
  }
  else
  {
    //Child, first command
    if(execlp(argv[1], argv[1], (char*)NULL)==-1)
    {
      printf("Couldn't execute first command\n");
      exit(-1);
    }
  }
  return 0;
}

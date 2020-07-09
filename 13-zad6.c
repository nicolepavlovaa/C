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
    printf("Couldnt fork\n");
    exit(-1);
  }
  else if(pid>0)
  {
    //parent
    printf("Waiting for child to finish\n");
    wait(&status);
    if(status==0)
    {
      exit(0);
    }
    printf("Child finished with exit code %d\n", status);
    pid=fork();
    if(pid==-1)
    {
      printf("Couldnt fork\n");
      exit(-1);
    }
    else if(pid>0)
    {
      //parent
      printf("Waiting for child to finish\n");
      wait(&status);
      printf("Child finished with exit code %d\n", status);
    }
    else
    {
      //Child
     if(execlp(argv[2], argv[2], (char*)NULL)==-1)
     {
       printf("Second command couldnt be executed\n");
       exit(-1);
     }
    }
  }
  else
  {
    //child
    if(execlp(argv[1], argv[1], (char*)NULL)==-1)
    {
      printf("First command couldnt be executed\n");
      exit(-1);
    }
  }
  return 0;
}

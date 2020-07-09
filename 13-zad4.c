#include <fcntl.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc>=2)
  {
    int status;
    int pid=fork();
    if(pid==-1)
    {
      perror("Couldn't fork\n");
      exit(-1);
    }
    if(pid>0)
    {
      //parent
      printf("Waiting for child to finish...\n");
      wait(&status);
      printf("Child exited with code %d\n", status);
    }
    else
    {
      //child
      //char* copy[argc];
      //for(int i=0; i<argc-1; i++)
      //{
      //  copy[i]=argv[i+1];
      //}
      //copy[argc-1]=(char*)NULL;
      if(execvp(argv[1], &argv[1])==-1)
      {
        printf("Couldn't execute\n");
        exit(-1);
      }
    }
    return 0;
  }
  printf("Not enough arguments\n");
  return 1;
}

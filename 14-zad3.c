#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int status;
  int counter=0;
  for(int i=1; i<argc; i++)
  {
    int pid=fork();
    if(pid==-1){perror("Couldnt fork\n"); exit(-1);}
    if(pid==0)
    {
      //printf("%d\n",i);
      //printf("child pid %d from parent pid %d\n",getpid(),getppid());
      if(execlp(argv[i], argv[i], (char*)NULL)==-1)
      {
        printf("Couldnt execute\n");
        exit(-1);
      }
      exit(0);
    }
    if(pid>0)
    {
      wait(&status);
      counter++;
      if(i==argc-1)
      {
        printf("%d\n",counter);
      }
    }
  }
  return 0;
}

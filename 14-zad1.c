#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int fd=open("abc", O_CREAT| O_WRONLY, 0644);
  int status;
  char buff[]="hello";
  if(fd==-1){printf("Unable to create file\n"); return 1;}
  int pid=fork();
  if(pid==-1){perror("Couldnt fork\n"); exit(-1);}
  else if(pid>0)
  {
    //parent
    wait(&status);
    printf("Child 1 exited with status %d\n", status);
    pid=fork();
    if(pid==-1){perror("Couldnt fork\n"); exit(-1);}
    else if(pid>0)
    {
      wait(&status);
      printf("Child 2 exited with status %d\n", status);
    }
    else
    {
      //Child2
      if(write(fd, buff, sizeof(buff))==-1)
      {
        printf("Couldnt write in file\n");
        exit(-1);
      }
    }
  }
  else
  {
    //Child1
    if(write(fd, buff, sizeof(buff))==-1)
    {
      printf("Couldnt write in file\n");
      exit(-1);
    }
  }
  return 0;
}

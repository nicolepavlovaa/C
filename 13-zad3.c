#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
  if(argc>=2)
  {
    int status=0;
    int pid=fork();
    if(pid==-1)
    {
      perror("Cannot fork\n");
      exit(-1);
    }
    else if(pid>0)
    {
      wait(&status);
      printf("%s\n", argv[1]);
    }
    else
    {
      if(execlp(argv[1], argv[1], (char*)NULL)!=-1)
      {
        write(1, argv[1], sizeof(argv[1]));
      }
      else
      {
        printf("Error\n");
        exit(-1);
      }
    }
    return 0;
  }
  return 1;
}

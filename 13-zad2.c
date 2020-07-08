#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int pid=fork();
  if(pid==-1)
  {
    printf("COuldn't fork\n");
    exit(-1);
  }
  else if(pid>0)
  {
    printf("Parent ID is %d and its parent's is %d\n", getpid(), getppid());
  }
  else
  {
    for(int i=0; i<10000; i++){}
    printf("Child ID is %d and its parent's is %d\n", getpid(), getppid());
  }
  return 0;
}

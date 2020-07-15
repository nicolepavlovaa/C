#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <stdlib.h>

int toNum(char str[10])
{
  int result=0;
  for(int i=0; i<10 && str[i]!='\n'; i++)
  {
    result++;
  }
  char copy[result];
  for(int i=0; i<result; i++)
  {
    copy[i]=str[i];
  }
  return atoi(copy);
}
int main(int argc, char* argv[])
{
  int n=1;
  char buff;
  int counter=1;
  char start[10];
  char end[10];
  read(0,start,10);
  read(0,end,10);
  int st=toNum(start);
  int e=toNum(end);
  printf("THIS %d, %d", st, e);
  int fd=open(argv[1], O_RDONLY);
  if(fd==-1) return 1;
  while((n=read(fd, &buff, 1))!=0)
  {
    if(counter>=st && counter<=e)
    {
      int a=write(1, &buff, 1);
      if(a==-1) return 1;
    }
    counter++;
    if(buff=='\n') counter=1;
  }
  return 0;
}

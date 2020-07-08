#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  if(argc!=3)
  {
    printf("Wrong num of arguments\n");
    return 1;
  }
  int f1= open(argv[1], O_RDONLY);
  if(f1==-1)
  {
    printf("No such file\n");
    return 1;
  }
  int f2=open(argv[2], O_CREAT | O_WRONLY | O_TRUNC);
  if(f2==-1)
  {
    printf("Cannot open/create file");
    return 1;
  }
  char* buff[10];
  int result=1;
  while(result!=0)
  {
    result=read(f1, buff, 10);
    if(result==-1)
    {
      printf("Error while reading\n");
      return 1;
    }
    if(result!=0)
    {
      write(fd2, buff, result);
    }
  }
  if(close(f1) == -1)
  {
    printf("some error occured\n");
    return 1;
  }
  if(close(f2)== -1)
  {
    printf("some error occured\n");
    return 1;
  }
  return 0;
}

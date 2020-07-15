#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  int n=1;
  int lines=1;
  int counter=0;
  char buff[1];
  int fd=open(argv[1], O_RDWR | O_APPEND, 0644);
  if(fd==-1) return 1;
  while((n=read(fd, buff, 1))!=0)
  {
    if(n==-1) return 1;
    if(lines<=10)
    {
      int a=write(1, buff, n);
      if(a==-1) return 1;
    }
    else
    {
      write(2, buff, n);
      //if(a==-1) return 1;
      counter++;
    }
    if(buff[0]=='\n') lines++;
    //printf("%d",lines);
  }
  char buff2[100];
  n=read(0, buff2, sizeof(buff2));
  if(n==-1) return 1;
  for(int i=0; i<counter; i++)
  {
    int w=write(fd,buff2,n);
    if(w==-1) return 1;
  }
  close(fd);
  return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc==2)
  {
    int fd=open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(fd==-1)
    {
      printf("Error in opening file\n");
      return 1;
    }
    int n=1;
    char buff[100];
    while((n=read(0, buff, sizeof(buff)))!=0)
    {
      if(n==-1)
      {
        printf("Error while reading\n");
        return 1;
      }
      int a=write(fd, buff, n);
      if(a==-1)
      {
        printf("Error in writing in file\n");
        return 1;
      }
    }
  }
  return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc> 2)
  {
    for(int i=1; i< argc; i++)
    {
      char buff[100];
      int fd=open(argv[i], O_RDONLY);
      if(fd==-1)
      {
        printf("Error in opening file\n");
        return 1;
      }
      int n=1;
      while((n=read(fd, buff, sizeof(buff)))!=0)
      {
        if(n==-1)
        {
          printf("Error in reading from file\n");
          return 1;
        }
        int w=write(1, buff, n);
        if(w==-1)
        {
          printf("Error while writing\n");
          return 1;
        }
      }
      int c=close(fd);
      if(c==-1)
      {
        printf("Error in closing file\n");
      }
    }
    return 0;
  }
  printf("Wrong number of arguments\n");
  return 1;
}

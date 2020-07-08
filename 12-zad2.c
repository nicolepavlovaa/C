#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc>1)
  {
    int n=1;
    char buff[100];
    int flag=0;
    while((n=read(0, buff, sizeof(buff)))!=0)
    {
      for(int i=1; i<argc; i++)
      {
        int fd=1;
        if(flag==0)
        {
          fd=open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        }
        else
        {
          fd=open(argv[i], O_WRONLY | O_APPEND, 0644);
        }
        write(fd, buff, n);
        close(fd);
      }
      flag=1;
      write(1, buff, n);
    }

  }
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc==3)
  {
    int fd=open(argv[1], O_RDONLY);
    int fd2=open(argv[2], O_WRONLY | O_APPEND | O_CREAT, 0644);
    if(fd==-1 || fd2==-1)
    {
      printf("Unable to open file\n");
      return 1;
    }
    int res=1;
    char buff[100];
    int counter=0;
    while((res=read(fd, buff, sizeof(buff)))!=0)
    {
      for(int i=0; i< res; i++)
      {
        if(counter>2)
        {
          counter=-1;
        }
        if(counter>-1 && counter<3)
        {
          //printf("%c|",buff[i]);
          int res2=write(fd2, &buff[i], 1);
          if(res2==-1)
          {
            printf("An error occurred while writing to file\n");
            return 1;
          }
          counter++;
        }
        if(buff[i]=='\n')
        {
          counter=0;
        }
      }
    }
    if(close(fd)==-1 || close(fd2)==-1)
    {
      printf("Unable to close file\n");
      return 1;
    }
    return 0;
  }
  printf("Wrong number of parameters\n");
  return 1;
}

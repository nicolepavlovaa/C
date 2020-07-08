#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc==2)
  {
    int fd=open(argv[1], O_RDWR | O_CREAT, 0644);
    if(fd==-1)
    {
      printf("Unable to open or create file %s\n", argv[1]);
      return 1;
    }
    char buff[20];
    int res=1;
    while((res=read(0, buff, sizeof(buff)))!=0)
    {
      if(res==-1)
      {
        printf("An error occurred while reading\n");
        return 1;
      }
      if(write(fd, buff, res)==-1)
      {
        printf("An error occurred while writing on %s\n", argv[1]);
        return 1;
      }
      //printf("%.*s\n",res, buff);
    }
    if(close(fd)==-1)
    {
      printf("Unable to close file %s\n", argv[1]);
      return 1;
    }
    fd=open(argv[1], O_RDONLY);
    if(fd==-1)
    {
      printf("Unable to open file %s\n", argv[1]);
    }
    while((res=read(fd, buff, sizeof(buff)))!=0)
    {
      if(res==-1)
      {
        printf("An error occurred while reading\n");
        return 1;
      }
      for(int i=0; i<res; i++)
      {
        int c=0;
        if(c==-1)
        {
          printf("An error occurred while writing\n");
          return 1;
        }
        if(buff[i]=='\t')
        {
          c=write(2, ">>>", 3);
        }
        else
        {
          c=write(2, &buff[i], 1);
        }
      }
    }
    return 0;
  }
  printf("Wrong number of arguments\n");
  return 1;
}

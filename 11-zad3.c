#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
  if(argc==2)
  {
    int f1=open(argv[1], O_CREAT | O_RDWR, 0644);
    if(f1==-1)
    {
      printf("Unable to open or create file %s\n", argv[1]);
      return 1;
    }
      char buff[25];
      if(write(f1, &buff, 25)==-1)
      {
        printf("Some error occured while writing in %s\n", argv[1]);
        return 1;
      }
      int res=1;
      char buff2[10];
      lseek(f1, 0, SEEK_SET);
      while((res=read(f1, buff2, 10))!=0)
      {
        if(res==-1)
        {
          printf("Some error occured while readng from %s\n", argv[1]);
          return 1;
        }
        printf("Read: %d\n", res);
      }
      if(close(f1)==-1)
      {
        printf("Some error occurred while closing %s\n", argv[1]);
        return 1;
      }
      return 0;
  }
  printf("Wrong number of arguments");
  return 1;
}

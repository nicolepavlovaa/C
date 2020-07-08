#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  if(argc==1)
  {
    char buff[50];
    int res=1;
    int res2=1;
    while((res=read(0, buff, sizeof(buff)))!=0)
    {
      if(res==-1)
      {
        printf("An error occurred while reading\n");
        return 1;
      }
      res2=write(1, buff, res);
      if(res2==-1)
      {
        printf("An error occurred while writing\n");
        return 1;
      }
    }
    return 0;
  }
  printf("Wrong number of arguments\n");
  return 1;
}

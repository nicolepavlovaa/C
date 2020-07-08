#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int toint(char* str)
{
  int result=0;
  for(int i=0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++)
  {
    result = (str[i] - '0') + result*10;
  }
  return result;
}

int main(int argc, char* argv[])
{
  if(argc==4)
  {
    int fd=open(argv[3], O_RDONLY);
    char buff[1];
    int n=1;
    int start=toint(argv[1])-1;
    int end=toint(argv[2])-1;
    int i=0;
    while((n=read(fd, buff, 1))!=0)
    {
      if(n==-1)
      {
        printf("Error while reading\n");
        return 1;
      }
      if(i>=start && i<=end)
      {
        int w=write(1, buff, n);
        if(w==-1)
        {
          printf("Error while writing\n");
          return 1;
        }
      }
      if(buff[0]=='\n')
      {
        i=-1;
        printf("\n");
      }
      i++;
    }
    if(close(fd)==-1)
    {
      printf("Error in closing file\n");
    }
    return 0;
  }
  printf("Wrong number of parameters\n");
  return 1;
}

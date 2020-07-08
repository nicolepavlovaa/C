#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int calclines(char buff[512], int nbytes)
{
  int res=0;
  for(int i=0; i<nbytes; i++)
  {
    if(buff[i]=='\n')
    {
      res=res+1;
    }
  }
  return res;
}
int calcwords(char buff[512], int nbytes)
{
  int res=0;
  for(int i=0; i<nbytes-1; i++)
  {
    if(buff[i]!=' ' && (buff[i+1]==' ' || buff[i+1]=='\n' || i+1==nbytes-1))
    {
      res=res+1;
    }
  }
  return res;
}

int main(int argc, char* argv[])
{
  int chars=0;
  int words=0;
  int lines=0;

  if(argc==1)
  {
    char buff[512];
    int nbytes=0;
    while((nbytes=read(0,buff,sizeof(buff)))!=0)
    {
      if(nbytes==-1)
      {
        printf("An error occured while reading.");
        return 1;
      }
      lines=calclines(buff, nbytes);
      chars=nbytes;
      for(int i=0; i<nbytes-1; i++)
      {
        if(buff[i]!=' ' && (buff[i+1]==' ' || buff[i+1]=='\n' || i+1==nbytes-1))
        {
          words=words+1;
        }
      }
    }
    printf("%d %d %d\n",lines, words, chars);
    return 0;
  }
  if(argc>1)
  {
    int fd;
    int totallines=0;
    int totalwords=0;
    int totalchars=0;
    for(int i=1; i<argc; i++)
    {
      fd=open(argv[i], O_RDONLY);
      if(fd==-1)
      {
        printf("Cannot open %s\n", argv[i]);
      }
      else
      {
        char buff[512];
        int nbytes=0;
        while((nbytes=read(fd, buff, sizeof(buff)))!=0)
        {
          if(nbytes==-1) {printf("Some error occured while reading\n."); return 1;}


        int l=calclines(buff,nbytes);
        int w=calcwords(buff, nbytes);
        printf("%d %d %d %s\n", l, w, nbytes, argv[i]);
        totallines=totallines+l;
        totalwords=totalwords+w;
        totalchars=totalchars+nbytes;
      }
    }
    }
    if(argc>2) {printf("%d %d %d total\n", totallines, totalwords, totalchars);}
    return 0;
  }
  return 0;
}

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512][512];

void
errorhandling(int fd)
{

  int i,j,n;
//  int w=100;
  char s[100];


  while((n = read(fd, buf, sizeof(buf))) > 0) 
{
     for(i=0;i<sizeof(buf);i++)
{
      for(j=i+1;j<sizeof(buf);j++)
{
	if(strcmp(buf[i],buf[j])>0)
{
         strcpy(s,buf[i]);
         strcpy(buf[i],buf[j]);
         strcpy(buf[j],s);
}
}
}
//printf("The sorted order of names are:");
  // for(i=0;i<n;i++)
//{
//printf("%s",buf[i]);
//}
//}

    if (write(1, buf, n) != n) {
      fprintf(2, "Sort: write error\n");
      exit(1);
    }
  }
  if(n < 0){
    fprintf(2, "Sort: read error\n");
    exit(1);
  }

}


int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1)
  {
    errorhandling(0);
    exit(0);
  }

  for(i = 1; i < argc; i++)
   {
    if((fd = open(argv[i], 0)) < 0)
    {
       fprintf(2, "Sort: Cannot Open %s\n", argv[i]);
       exit(1);
    }
    else
    {
      printf("!! File Opened !!\n");
    } errorhandling(fd);
      exit(0);
   }


return 0;
}

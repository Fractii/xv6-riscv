#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      fprintf(2, "cat: write error\n");
      exit(1);
    }
  }
  if(n < 0){
    fprintf(2, "cat: read error\n");
    exit(1);
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit(0);
  }
if(strcmp(argv[1], "-n") == 0)// "==" compares pointers but strcmp compares t>
  {
        for (i=0;i<argc;i++)
        { printf(" %d",i);
//      fd = open(while ((c = getc(fp)) != EOF) {     /* read each character */
 //       if (last)                       /* test if last set */
   //         putchar (last);             /* output all characters */
     //   if (last == '\n')               /* test if last is newline */
       //     printf ("%06zu ", ln++);    /* output next line number */
       // last = c;
        }
        for (i=2;i<argc;i++)
        {
         if((fd = open(argv[i], 0)) < 0){
      fprintf(2, "cat: cannot open %s\n", argv[i]);
      exit(1);
        }
         cat(fd);
	close(fd);
	}
}
else
{
  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      fprintf(2, "cat: cannot open %s\n", argv[i]);
      exit(1);
    }
    cat(fd);
    close(fd);
        }
         cat(fd);


 exit(0);
}
return 0;
}

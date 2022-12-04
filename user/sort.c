#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];
char buf1[512];
void
errorhandling(int fd)
{
int j,n,k;
char buf2[512];
char buf3[512];

	//loop until all bytes are read, byte size being read are stored in n
	while((n = read(fd, buf, sizeof(buf))) > 0)
	{
		for(k=0;k<n;k++)
		{
		     if(buf[k] != '\n')
		     {
			strcpy(buf1,buf);
			//printf("%c",buf1[k]);		     
		     }

		        else
			{
				for(j=k+1;j<n;j++)
				{
					if(buf[j] != '\n')
					{
					      	strcpy(buf2,buf);
					      	printf("%c",buf2[j]);
					}
					else
					{
						
					if(buf2[0]>buf1[0])
					{ 
				        	strcpy(buf3,buf2);
						strcpy(buf2,buf1);
						strcpy(buf1,buf3);
				        }
				        memset(buf2,0,512);
				//break;
					}	        
                              }
                              //exit(0);
                              //memset(buf1,0,512);
                        		//printf("%c\n",buf1[j]);
					//printf("%c",buf2[j]);
					//exit(0);      
			//break;        
			}
		}
		                                      
	}

	    if (write(1, buf3, n) != n) 
	    {
	      fprintf(2,"sort: write error\n");
	      exit(1);
	    }
	  if(n < 0)
	  {
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
       printf( "Sort: Cannot Open %s\n", argv[i]);
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

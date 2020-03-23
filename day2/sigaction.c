#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>


int i=0;

void quit(int code)
{
	fprintf(stderr,"\nInterrupt (code-%d,i=%d)\n",code,i);
	exit(1);
}
int main()
{
	struct sigaction newact;
	newact.sa_handler =quit;
	newact.sa_flags = 0;
	
	if(sigaction(SIGINT,&newact,NULL)==-1)
		exit(1);
		
	for(;;)
	{
		if(i++ %50000000 == 0)
		fprintf(stderr,".");
	}	
	return 0;		
}

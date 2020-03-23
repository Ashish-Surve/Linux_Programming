#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
void prExit(int status) 
{

	if(WIFEXITED( status ) )			//exit(7)
		printf("normal termination\n");
		
	else if(WIFSTOPPED( status ))		//abort()
		printf("child stopped, signal no.= %d\n",WSTOPSIG(status));
		
	else if(WIFSIGNALED( status ) )
		printf("abnormal termination, "         "signal no.= %d\n", WTERMSIG(status));
	
}


int main() 
{
	int status;
	if(fork() == 0) 
		//exit(7);/*normal*/
		abort();
		//status=status/0;
		wait(&status);
		prExit(status);
		
}

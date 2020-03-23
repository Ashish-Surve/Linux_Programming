#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int status;
	pid_t pid = fork();
	if(pid==0)
	{
		execlp("ls","ls",0);
		printf("Child Done....");
	}
	else
	{
		wait(&status);
		printf("Parent Gone...");
		
	}

	return 0;		
}

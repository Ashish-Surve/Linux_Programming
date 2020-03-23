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
		printf("Child\n");
	}
	else
	{
		printf("Parent going to sleep\n");
		sleep(10);
		printf("Parent Waking up\n");
	}

	return 0;		
}

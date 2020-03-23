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
		printf("Child going to sleep\n");
		sleep(10);
		printf("Child Waking up\n");
		printf("from child, pid = %d\n",getpid());
		printf("from child, ppid = %d\n",getppid());
	}
	else
	{
		printf("Parent waiting\n");
		wait(&status);
		printf("Child exited normally");
		
	}

	return 0;		
}

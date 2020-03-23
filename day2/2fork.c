#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int i=8;
	pid_t pid = fork();
	if(pid==0)
	{
		i=10;
		printf("from child, pid = %d\n",getpid());
		printf("from child, ppid = %d\n",getppid());
	}
	else
	{
		printf("from parent, pid = %d\n",getpid());
		printf("from parent, ppid = %d\n",getppid());
		printf(" Return Value of fork = %d\n ",pid);
	}

	return 0;		
}

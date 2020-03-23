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
		printf("from child, i = %d\n",i);
	}
	else
	{
		printf("From Parent i = %d\n",i);
	}
		
	return 0;		
}

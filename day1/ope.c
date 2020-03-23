#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
	int fd = open("op.txt",O_CREAT|O_WRONLY|O_EXCL,S_IRUSR|S_IWUSR|S_IRGRP);
	printf("File Descriptor no is %d\n",fd);
	write(fd,"Hello World\n",12);
	write(fd,"Bye World\n",10);
	close(fd);
	return 0;
}

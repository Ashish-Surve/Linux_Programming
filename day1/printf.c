#include<unistd.h>
#include<sys/types.h>

int main()
{
	write(1,"Hello World\n",13);
	return 0;
}

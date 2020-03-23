#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h>           

int main()
{
	unlink("some.txt");
}

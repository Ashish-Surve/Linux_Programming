#include "tcp_header.h"

int main(int argc, char *argv[])
{
	int sd =0,n=0;
	struct sockaddr_in serv_addr;
	char buff[1024];
	
	sd = socket(AF_INET,SOCK_STREAM,0);
	
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(buff,'0',sizeof(buff));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port = htons(9001);
	
	inet_pton(AF_INET,argv[1], &serv_addr.sin_addr);
	connect(sd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	printf("Client Ready\n");
	while((n=read(sd,buff,sizeof(buff)-1))>0)
	{
		write(1,buff,n);
	}
	return 0;
}

#include "tcp_header.h"

int main()
{
	int sd =0,conn=0;
	struct sockaddr_in serv_addr;
	char buff[1024];
	time_t ticks;
	
	sd = socket(AF_INET,SOCK_STREAM,0);
	
	memset(&serv_addr,'0',sizeof(serv_addr));
	memset(buff,'0',sizeof(buff));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(9001);
	bind(sd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
	listen(sd,10);
	while(1)
	{
		conn=accept(sd,(struct sockaddr*)NULL,NULL);
		ticks = time(NULL);
		snprintf(buff,sizeof(buff),"%.24s",ctime(&ticks));
		write(conn,buff,strlen(buff));
		close(conn);
		sleep(1);
	}
	
}

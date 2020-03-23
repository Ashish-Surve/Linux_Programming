#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include<sys/types.h>
void* func(void *arg)
{
	int *x = (int *)arg;
	printf("Thread starts... = %x\n",pthread_self());
	//sleep(2);
	while(++(*x)<100);
	printf("Thread ends\n");
	return NULL;
} 

int main()
{
	int err;
	int x=0,y=0;
	pthread_t tid;
	err= pthread_create(&tid,NULL,&func,&x);
	printf("Thread created with tid = %x\n",tid);
	while(++y<10000);
	pthread_join(tid,NULL);
	printf("Back to main x=%d y=%d\n",x,y);
	return 0;
}

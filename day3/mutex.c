#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int counter =0;

//pthread_mutex_t m1= PTHREAD_MUTEX_INITIALIZER;
sem_t m1;
void* func()
{
	int i=0;
	//pthread_mutex_lock(&m1);
	sem_wait(&m1);				
	while(i<3)
	{
		printf("ThreadID = %d\n",pthread_self());
		counter++;
		printf("Counter = %d\n",counter);
		sleep(1);
		i++;
	}
	sem_post(&m1);		//upping the semphore
}

int main()
{
	int rc1,rc2;
	pthread_t t1,t2;
	sem_init(&m1,0,1);
	rc1 = pthread_create(&t1, NULL, &func,NULL);
	rc2 = pthread_create(&t2, NULL, &func,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&m1);
	return 0;
}

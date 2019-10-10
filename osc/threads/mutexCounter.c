#include<stdio.h>
#include <pthread.h>
pthread_mutex_t mutex_1;
int c=0;
void hello(){
	pthread_mutex_lock(&mutex_1);
	int i;
	for (i = 0; i < 100000; ++i)
	{
		c++;
	}
	pthread_mutex_unlock(&mutex_1);

}
int main(int argc, char const *argv[])
{
	int i;
	if(pthread_mutex_init(&mutex_1,NULL)!=0){
		printf("Failed mutex\n");
		return 1;
	}
	pthread_t thread[10];
	for (i = 0; i < 10; ++i)
	{	
		pthread_create(&thread[i],NULL,(void*) hello, NULL);
	}
	for (i = 0; i < 10; ++i)
	{	
		pthread_join(thread[i],NULL);
	}
	printf("%d\n",c );
	return 0;
}
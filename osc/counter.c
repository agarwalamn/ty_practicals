#include<stdio.h>
#include <pthread.h>
#include<unistd.h>

int c=0;
void hello(){
	int i;
	for (i = 0; i < 100000; ++i)
	{
		c++;
	}

}
int main(int argc, char const *argv[])
{
	int i;
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
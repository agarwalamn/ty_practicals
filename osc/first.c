#include<stdio.h>
#include <pthread.h>
#include<unistd.h>

int c=0;
void hello(){
	c+=1;
	printf("Hello world~! from thread %d\n",c);

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
	return 0;
}
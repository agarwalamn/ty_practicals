#include<stdio.h>
#include<pthread.h>
#define arr_size 1000
#define thread_c 10

int arr[arr_size];
int global_index=0;
int sum=0;
pthread_mutex_t mutex_1;

void slave(){
	int local_index,partial_sum=0;
	do{
		pthread_mutex_lock(&mutex_1);
		local_index=global_index;
		global_index++;
		pthread_mutex_unlock(&mutex_1);
		if(local_index< arr_size){
			partial_sum = partial_sum+*(arr+local_index);
		}
	}while(local_index<arr_size);
	pthread_mutex_lock(&mutex_1);
	sum+=partial_sum;
	pthread_mutex_unlock(&mutex_1);

}
int main(){
	pthread_mutex_init(&mutex_1,NULL);
	int i;
	pthread_t threads[thread_c];
	for (i = 0; i < arr_size; ++i)
	{
		arr[i]=i+1;
	}
	for (i = 0; i < thread_c; ++i)
	{
		pthread_create(&threads[i],NULL,(void*)slave,NULL);
	}
	for (i = 0; i < thread_c; ++i)
	{
		pthread_join(threads[i],NULL);
		
	}
	printf("Sum %d\n",sum );
	return 0;
}
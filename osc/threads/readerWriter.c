#include<stdio.h>
#include<pthread.h>
#define size 100000

int arr[size];
int head=0,tail=0;
pthread_mutex_t mutex_t;
int count=0,count_r;

void writer(){
	pthread_mutex_lock(&mutex_t);
	int i=0;
	for (head; head < size; head++)
	{
		arr[head]=(head+1)*10;
		printf("writer wrote at %d value %d\n",head,arr[head]);
		if (i==10000) break;
		i++;
	}
	count+=1;
	printf("Thread %d \n",count);
	printf("head %d\n", head);
	if(head==99999) printf("Arrayfull\n");
	pthread_mutex_unlock(&mutex_t);
}

void reader(){
	pthread_mutex_lock(&mutex_t);
	int i=0;
	for (tail; tail < head; tail++){
		printf("reader reading at %d value %d\n",tail,arr[tail]);
		if (i==20000) break;
		i++;
	}
	count_r+=1;
	printf("Thread read %d \n",count_r);
	printf("tail %d\n", tail);
	if(tail>=head) printf("Arrayfull\n");
	pthread_mutex_unlock(&mutex_t);
}

int main(){
	arr[0]=10;arr[1]=20;arr[2]=30;arr[3]=40;arr[4]=50;
	head=5;
	pthread_mutex_init(&mutex_t,NULL);
	pthread_t w[10],r[5];
	int i=0;
	//writer thread create
	for (i = 0; i < 10; ++i){
		pthread_create(&w[i],NULL,(void*)writer,NULL);
	}
	
	//reader thread create 
	for (i = 0; i < 5; ++i){
		pthread_create(&r[i],NULL,(void*)reader,NULL);
	}
	//writer thread join
	for (i = 0; i < 10; ++i){
		pthread_join(w[i],NULL);
		if(i%2==0){
			thread_join(r[i],NULL);
		}
	}
}

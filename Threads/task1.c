#include <stdio.h>
#include <pthread.h>

void* thread(void* arg){
	printf("Thread %ld is running.\n", pthread_self());
	return NULL;
}

int main(){
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	pthread_create(&thread1,NULL,thread,NULL);
	pthread_create(&thread2,NULL,thread,NULL);
	pthread_create(&thread3,NULL,thread,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);

	return 0;
}


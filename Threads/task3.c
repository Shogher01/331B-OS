#include <stdio.h>
#include <pthread.h>

void* print(void* arg){
	long thread_id = (long) arg;
	printf("The thread id is %ld.\n", thread_id);
	for(int i =1; i<=5; i++){
		printf("%d \n",i);
	}

	return NULL;
}

int main(){
	pthread_t threads[3];

	for(int i=0; i<3;i++){
		pthread_create(&threads[i],NULL,print,(void*)(long)(i+1));
	}

	for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        }

	return 0;
}

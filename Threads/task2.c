#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define Size 8
int arr[Size] = {1,2,3,4,5,6,7,8};

void* sum(void* arg){
	int* indices = (int*) arg;
	int* sum = malloc(sizeof(int));
	*sum = 0;
	for(int i=indices[0];i<= indices[1];i++){
		*sum += arr[i];	
	}

	printf("The sum from index %d to %d is %d.\n", indices[0],indices[1],*sum);
	return (void*) sum;
}

int main() {
	pthread_t thread1, thread2;

	int thread1_args[2] = {0, Size/2-1};
	int thread2_args[2] = {Size/2,Size-1};

	pthread_create(&thread1,NULL, sum, (void*)thread1_args);
	pthread_create(&thread2,NULL, sum, (void*)thread2_args);
	
	int* result1;
	int* result2;
	pthread_join(thread1, (void**)&result1);
	pthread_join(thread2, (void**)&result2);

	printf("Total sum is %d.\n", *result1+*result2);

	free(result1);
	free(result2);
	return 0;

}

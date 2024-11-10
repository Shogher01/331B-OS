#include <stdio.h>
#include <pthread.h>

int array[] = {1,2,3,4,5};

void* square(void* arg){
	int num = *(int*)arg;
	printf("Square of %d is %d.\n", num, num*num);
	return NULL;
}

int main(){
	int size = sizeof(array)/ sizeof(array[0]);
        pthread_t threads[size];

	for (int i = 0; i < size; i++) {
        pthread_create(&threads[i], NULL, square, &array[i]);
        }

        for (int i = 0; i < size; i++) {
        pthread_join(threads[i], NULL);
        }

	return 0;
}

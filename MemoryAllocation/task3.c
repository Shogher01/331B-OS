#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr = (int *)malloc(10*sizeof(int));
	if(arr==NULL){
	printf("Error.");
	return 1;
	}
	printf("Input array elements.\n");
	for(int i=0; i<10; i++){
	scanf("%d",&arr[i]);
	}
	
	printf("\n");
	arr = (int*)realloc(arr,5*sizeof(int));
	if(arr==NULL){	
	printf("Error.");
        return 1;
        }

	for(int i=0;i<5;i++){
	printf("%d ",arr[i]);
	}
	free(arr);
	return 0;

	
}

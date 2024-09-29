#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Input the number of students.\n");
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(n*sizeof(int));
	if(arr==NULL){
	printf("Error.\n");
	return 1;
	}
	printf("Input the grades.\n");
	int highest = 0;
	int lowest = 101;
	for(int i =0; i<n;i++){
	scanf("%d",&arr[i]);
	if(highest<arr[i]){
		highest = arr[i];
	}
	if(lowest>arr[i]){
		lowest = arr[i];
	}
	}
	printf("Highest: %d\n", highest);
	printf("Lowest: %d\n", lowest);

	free(arr);
	return 0;

}

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n; 
	printf("Enter the size of the array.\n");
	scanf("%d",&n);
	
	int *arr = (int*)calloc(n, sizeof(int));
	if(arr == NULL){
	printf("Error");
	return 1;
	}
	
	printf("Array after calloc.\n");
	for (int i =0; i<n;i++){
	printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Input the element values of array.\n");
	int sum=0;
	for(int i=0; i<n;i++){
	scanf("%d",&arr[i]);
	printf("%d ", arr[i]);
	sum += arr[i];
	}
	printf("\n");
	printf("Avarage%.2f\n",(float)sum/n);
	free(arr);
	return 0;

}

#include <stdio.h>
#include <stdlib.h>

int main () {
	printf("Input the size of the array\n");
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(n*sizeof(int));
	if(arr == NULL){
		printf("Error\n");
		return 1;
	}
	int sum =0;
	printf("Please input the element values of the array\n");
	for(int i=0; i< n; i++){
	scanf("%d", &arr[i]);
	sum+=arr[i];
	}

	printf("Sum:%d\n", sum);
	
	free(arr);
	return 0;

}

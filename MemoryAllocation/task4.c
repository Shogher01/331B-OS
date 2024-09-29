#include <stdio.h>
#include <stdlib.h>


int main(){
	char **arr =(char**) malloc(3*sizeof(char*));
	if(arr==NULL){
	printf("Error.\n");
	return 1;
	}

	for(int i=0; i< 3;i++){
	arr[i] = (char*)malloc(50*sizeof(char));
	if(arr[i]==NULL){
	printf("Error.");
	return 1;
	}
	}

	printf("Input 3 strings.\n");
	for(int i=0;i<3;i++){
		scanf("%s",arr[i]);
	}

	char **arr_new = (char**)realloc(arr,5*sizeof(char*));
	if(arr_new==NULL){
        printf("Error.\n");
        return 1;
        }else{
	arr = arr_new;
	}

	for(int i=3; i< 5;i++){
        arr[i] = (char*)malloc(50*sizeof(char));
        if(arr[i]==NULL){
        printf("Error.");
        return 1;
        }
        }
	printf("Input 2 more strings.\n");
	for(int i=3;i<5;i++){
                scanf("%s",arr[i]);
        }

	for(int i=0;i<5;i++){
		printf("%s\n", arr[i]);
	}
	for (int i = 0; i < 5; i++) {
 		free(arr[i]);
	}
	free(arr);

	return 0;
}

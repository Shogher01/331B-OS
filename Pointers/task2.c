#include <stdio.h>

int main(){

int arr[5] = {1,1,2,3,5};
int *p = arr;

for(int i =0; i<5; i++) {
printf("%d ", *(p+i));
}

printf("\n");

*(p) = 7;
*(p+3) = 8;

printf("Modified array with pointer: \n");
for(int i =0; i<5; i++) {
printf("%d ", *(p+i));
}

printf("\n");

printf("Modified array with array name: \n");
for(int i =0; i<5; i++) {
printf("%d ", arr[i]);
}

printf("/n");
return 0;
}

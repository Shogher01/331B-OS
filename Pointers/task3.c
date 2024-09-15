#include <stdio.h>

void swap(int *a, int *b){
int t = *a;
*a = *b;
*b = t;
};

int main(){
int a = 3;
int b = 7;

printf("a = %d\n", a);
printf("b = %d\n", b);

printf("Swap\n");

swap(&a,&b);

printf("a = %d\n", a);
printf("b = %d\n", b);

return 0;

};

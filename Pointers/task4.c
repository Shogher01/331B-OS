#include <stdio.h>

int main() {
int a = 5;
int *p = &a;
int **pp = &p;

printf("Value of a with single pointer is %d\n", *p);
printf("Value of a with double pointer is %d\n", **pp);

return 0;

}

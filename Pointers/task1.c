#include <stdio.h>

int main() {
int n = 5;
int *p = &n;

printf("Address of integer with variable %p\n", &n);
printf("Address of integer with pointer %p\n", &p);

*p = 13;
printf("Updated value of n: %d\n", n);

return 0;
}



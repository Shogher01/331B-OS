#include <stdio.h>

int main() {
	int a;
	char b;
	double c;
	short d;

	printf("The size of int is: %lu\n", sizeof(a));
	printf("The size of char is: %lu\n", sizeof(b));
	printf("The size of double is: %lu\n", sizeof(c));
	printf("The size of short is: %lu\n", sizeof(d));


	printf("The address of int is: %p\n",&a);
	printf("The address of char is: %p\n",&b);
	printf("The address of double is: %p\n",&c);
	printf("The address of short is: %p\n",&d);

	// The output is:
	// The address of int is: 0x7fffda2fc89c
        // The address of char is: 0x7fffda2fc899
        // The address of double is: 0x7fffda2fc8a0
        // The address of short is: 0x7fffda2fc89a
	// If we look by arrangement sequence in the memory, we can see that
	// char is located first in location ending with 99: char can be placed
	// anywhere in the memory because the size is just 1. The next available 	// address after the char is 0x7fffda2fc89a, where short is located. 
	// The size of short is 2, and a(10) is divisible by 2. The next
	// available address is 0x7fffda2fc89c, where int is located. The size
	// of int is 4, and c(12) is divisible by 4. The next available 
	// location after int is 0x7fffda2fc8a0, where double is located,
	// the size of double is 8, and 0 is divisible by 8.
	return 0;

}

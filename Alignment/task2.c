#include <stdio.h>

struct str{
	char a;
	int b;
	double c;
};

struct revstr{
	double c;
	int b;
	char a;
};


int main(){
	struct str s1;
	struct revstr s2;

	printf("The size of str is: %lu\n", sizeof(s1));
	printf("The address of a in str is: %p\n", &s1.a);
	printf("The address of b in str is: %p\n", &s1.b);
	printf("The address of c in str is: %p\n", &s1.c);

	printf("\n");

	printf("The size of revstr is: %lu\n", sizeof(s2));
	printf("The address of a in revstr is: %p\n", &s2.a);
        printf("The address of b in revstr is: %p\n", &s2.b);
        printf("The address of c in revstr is: %p\n", &s2.c);

	/* Although char is taking 1 byte space, int 4, and double 8, and
	 * 1+4+8= 13, we can see that in both cases structures take up 
	 * 16 bytes. The reason is the padding of 3 bytes which exists 
	 * for proper memory allignment reasons.
	 * In str we can see that a is located in address ending with 0. 
	 * a is a char, so no special allignment is required. The next
	 * available address ends with 2, but as far as we have int b, and 
	 * it needs to be properly alligned, b is located in position 
	 * which is ending with 4, and int size is 4: 4 is divisible by 4,
	 * so int is properly alligned in its address. The next available
	 * address ends with 8, as int takes 4 bytes, and we can see that
	 * c which is double is located in that position. 8 is divisible 
	 * by 8, and double has size of 8, so c is properly alligned.
	 *
	 * When we change the sequence, we can see change in memory allignment
	 * is changing. 
	 * We can see that c, which is double, is located in position 
	 * ending with 0(0MOD8=0). The next available address is ending by 8,
	 * as double has size of 8. In the next address int is placed, which
	 * takes 4 bytes(8MOD4 = 0). The next available address is c(12),
	 * and we can see that c is placed there, which is char, and takes
	 * up 1 byte space. But still we can see that 3 more bytes are taken
	 * by revstr. The reason is str takes space alligning with the biggest
	 * data structure size that it has. In this case it is double, which
	 * has size of 8, so allignment needs to be divisible by 8. That is why
	 * padding 3 more bytes, to have space of 16 bytes(16MOD8=0).
	 */
       return 0;	
}

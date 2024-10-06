#include <stdio.h>

//#pragma pack(1)
//#pragma pack(2)
#pragma pack(4)
struct str{
        char a;
        int b;
        double c;
};


int main(){
        struct str s1;

        printf("The size of str is: %lu\n", sizeof(s1));
        printf("The address of a in str is: %p\n", &s1.a);
        printf("The address of b in str is: %p\n", &s1.b);
        printf("The address of c in str is: %p\n", &s1.c);

        printf("\n");
	
	/*
	 * When we are not adding pragma, we can see the standard alignment
	 * of the data structures, where each structure address is divisible
	 * by its size
	 *
	 * When we add pragma, it reallignes the memory allocation logic.
	 * When we specify the pack number, we tell the compiler by how many	         * byte boundaries the data structures should be alligned.
	 * We can see that when given pack(1), they are alligned tightly next
	 * to each other, that is why the struct size corresponds to the 
	 * sum of the lengths of data structures inside it (1+4+8=13).
	 * In case of pack(2), 2byte boundaries are counted, that is why
	 * we can see e.g. how char takes up 2 byte space(from *a to *c), hence
	 * totalling 14 bytes.
	 * In case of pack(4), 4byte boundaries are counted, that is why we
	 * can see how char takes 4 byte space, hence resulting 16 bytes 
	 * at the end.
	 */
	return 0;
}

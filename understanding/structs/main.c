#include <stdio.h>

/*
	How do structs look in memory?
	What does it look like when I pass a struct as a function parameter?
*/

struct mystruct {
	int i1;
	int i2;
	char *str1;
};

void test1(struct mystruct arg) {
	/*
		Assembly is generated to create a copy of the struct
		In test1's stack space.
	*/
	printf("%p\n", &arg);
}

void main() {
	struct mystruct a;
	a.i1 = 1;
	a.i2 = 2;
	a.str1 = "String in main's stack";
	printf("Size of struct: %d\nLocation: %p\n", sizeof(a), &a);
	test1(a);
}

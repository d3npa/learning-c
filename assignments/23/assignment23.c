#include <stdio.h>

struct example {
	int i;
};

struct example *ptr;

void main() {
	struct example test;
	ptr = &test;

	test.i = 1;
	printf("%d\n", test.i);

	(*ptr).i = 2;
	printf("%d\n", test.i);

	ptr->i = 3;
	printf("%d\n", test.i);
}

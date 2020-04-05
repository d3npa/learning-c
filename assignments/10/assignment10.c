#include <stdio.h>

void main()
{
	int array[10];
	int size = sizeof(array) / sizeof(array[0]);
	printf("This array has %d elements.\n", size);
}

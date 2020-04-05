#include <stdio.h>
#include <string.h>

void main(int argc, char **argv)
{
	char buf1[10];
	char buf2[10];
	strcpy(buf2, "hello");
	printf("%d, %d, %d\n", sizeof(buf1), sizeof(buf2), strlen(buf2));
}

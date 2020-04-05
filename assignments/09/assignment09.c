#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <firstname> <lastname>\n", argv[0]);
		return 1;
	}
	char *firstname = argv[1];
	char *lastname = argv[2];

	printf("Welcome %s %s\n", firstname, lastname);
	return 0;
}

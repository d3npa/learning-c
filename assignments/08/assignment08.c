#include <stdio.h>

void main()
{
	int input;
	printf("Enter a number between 1 and 500: ");
	scanf("%d", &input);

	char *format = "Your number is between %d and %d!\n";
	
	if (1 < input && input <= 100)
	{
		printf(format, 1, 100);
	}
	else if (100 < input && input <= 200)
	{
		printf(format, 101, 200);
	}
	else if (200 < input && input <= 300)
	{
		printf(format, 201, 300);
	}
	else if (300 < input && input <= 400)
	{
		printf(format, 301, 400);
	}
	else if (400 < input && input <= 500)
	{
		printf(format, 401, 500);
	}
	else
	{
		printf("Your number was not in any of our ranges.\n");
	}

	printf("You entered: %d\n", input);
}

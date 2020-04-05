#include <stdio.h>

void main() {
	char answer;
	int index = 0;
	float scores[10];
	while (answer != 'N') {
		printf("Enter a test score: ");
		scanf("%f", &scores[index++]);
		printf("Would you like to continue? Y/N ");
		scanf("\n%c", &answer);
	}

	int i;
	float average;
	for (i = average = 0; i < index; average += scores[i++]);
	average /= index;
	printf("Your average is %.2f\n", average);
}

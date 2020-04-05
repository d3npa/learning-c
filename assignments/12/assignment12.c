#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int times;
	printf("How many times would you link to flip the coin? ");
	scanf("%d", &times);

	srand(time(NULL));
	int i, heads, tails;
	i = heads = tails = 0;
	while (i++ < times) {
		if (rand() % 2 == 0) {
			heads++;
		} else {
			tails++;
		}
	}

	printf("After flipping the coin %d times, the results were\n", times);
	printf("%d heads\n%d tails\n", heads, tails);
}

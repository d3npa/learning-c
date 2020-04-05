#include <stdio.h>

void main() {
	int score;
	int scores[5][4];

	for (int g = 0; g < 4; g++) {
		printf("# Game %d\n", g + 1);
		for (int p = 0; p < 5; p++) {
			printf("Enter score for player %d: ", p + 1);
			scanf("%d", &score);
			scores[p][g] = score;
		}
	}

	int best_index = 0;
	float best_score = 0;
	for (int p = 0; p < 5; p++) {
		float average = 0;
		for (int g = 0; g < 4; g++) {
			average += scores[p][g];
		}
		average /= 4;

		if (average > best_score) {
			best_index = p;
			best_score = average;
		}

		printf("Player #%d average: %.2f\n", p + 1, average);
	}

	char *verdict = "Player #%d had the highest scoring average at %.2f points"
					" per game.\n";
	printf(verdict, best_index + 1, best_score);
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
struct stats {
	int points;
	int games;
} players[SIZE];

int read_integer() {
	char buffer[8];
	fgets(buffer, sizeof(buffer), stdin);
	return atoi(buffer);
}

void main() {
	for (int i = 0; i < SIZE; i++) {
		printf("Enter Player %d's point total: ", i+1);
		int points = read_integer();
		printf("Enter Player %d's game total: ", i+1);
		int games = read_integer();

		struct stats *player = &players[i];
		player->points = points;
		player->games = games;
	}

	for (int i = 0; i < SIZE; i++) {
		struct stats player = players[i];
		float average = (float) ((float) player.points / (float) player.games);
		printf("Player %d's scoring average was %.2f ppg\n", i+1, average);
	}
}

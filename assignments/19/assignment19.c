#include <stdio.h>
#include <stdlib.h>

void main() {
	char *p = malloc(32);
	if (p == NULL) {
		printf("Failed to allocate heap space.");
		exit(1);
	} else {
		printf("Allocated heap space at %p.\n", p);
	}

	// Do things

	free(p);
}

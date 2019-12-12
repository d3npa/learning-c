#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int readline(char **buffer) {
	/*
	 * Reads a string from STDIN until a newline character '\n' is reached.
	 * Replaces the final '\n' with a NULL byte.
	 * Returns the number of bytes read.
	 */
    int blocksize = 8;
	int buflen = blocksize;
	if (buffer == NULL) {
		printf("Address of buffer is NULL\n");
		return -1;
	}
	if (*buffer == NULL) {
		if ((*buffer = (char *) malloc(buflen)) == NULL) {
			puts("Failed to allocate memory\n");
			return -1;
		}
	}
	char *buf = *buffer;
	// printf("[*] Address of buffer: %p\n", buf);
	int bytesRead = 0;
	while (bytesRead < buflen) {
		/*
		 * 1. Read one char
		 * 2. Check for stop character
		 * 3. Increase buffer size if needed
		 * 4. Append new char to buf
		 */
		char c[1];
		read(0, &c, 1);
		if (c[0] == '\n') {
            // Newline! Break
			*((char *) (buf + bytesRead)) = '\0';
			break;
		}
		else {
			*((char *) (buf + bytesRead++)) = c[0];
			if (bytesRead == buflen) {
				buflen += bytesRead;
				buf = realloc(buf, buflen);
			}
		}
	}
	return bytesRead;
}

void main() {
	char *fname = NULL;
	char *lname = NULL;

    // printf isn't flushing stdout on its own for some reason???
    // printf("Enter your first name: ");
    // printf("%s", "Enter your first name: ");
    // fflush(0);
    write(1, "Enter your first name: ", 23);
	if (readline(&fname) == -1) exit(-1);
    write(1, "Enter your last name: ", 22);
    if (readline(&lname) == -1) exit(-1);

	printf("Hello %s %s!\n", fname, lname);
	free(fname);
    free(lname);
}

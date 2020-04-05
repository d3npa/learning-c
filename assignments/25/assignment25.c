#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
	int fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		puts("An error occured when trying to open a file.");
		return -1;
	} else {
		puts("Successfully received file handle!");
	}

	char *buffer = "test data\n";
	int length = strlen(buffer);
	int bytes = write(fd, buffer, length);
	printf("Wrote %d/%d bytes; ", bytes, length);
	if (bytes != length) {
		puts("write operation did not succeed.");
	} else {
		puts("successfully wrote to file!");
	}

	close(fd);
	return 0;
}

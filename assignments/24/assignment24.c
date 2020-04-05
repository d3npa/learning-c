// #include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("test.txt", O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		puts("An error occured when trying to open a file.");
	} else {
		puts("Successfully received file handle!");
	}

	return fd > 0 ? 0 : fd;
}

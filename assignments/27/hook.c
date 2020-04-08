#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

int write (int fd, const void *buf, int n) {
	int (*real_write) (int, const void *buf, int);
	real_write = dlsym(RTLD_NEXT, "write");
	printf("[Debug] Real write is at %p\n", real_write);
	
	if (strcmp((char *)buf, "Hello, world!\n") == 0) {
		buf = "Goodbye, cruel world!\n";
		n = 22;
	}

	return real_write(fd, buf, n);
}

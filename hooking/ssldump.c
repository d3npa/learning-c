#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <openssl/ssl.h>

#define SSL_READ 0
#define SSL_WRITE 1

void log_ssl(int direction, char *buf, int num) {
	int fd = open("ssldump.txt",
			O_CREAT | O_WRONLY | O_APPEND,
			S_IRUSR | S_IWUSR);

	// Loop until end of buf (specified by num)
	int cursor = 0;
	while (cursor < num) {
		// Get the distance to the next \n or \0
		int d;
		// while (buf[cursor+d] && buf[cursor+d++] != '\n');
		for (d = 0; buf[cursor+d] && buf[cursor+d] != '\n'; d++);

		if (d == 0) {
			cursor++;
			continue;
		}

		// Print direction symbol
		if (direction == SSL_WRITE) {
			write(fd, "\x1b[92m> \x1b[0m", 11);
		} else if (direction == SSL_READ) {
			write(fd, "\x1b[96m< \x1b[0m", 11);
		}

		write(fd, &buf[cursor], d++); // d++ makes it skip the \n or \0
		write(fd, "\n", 1); // always prints a \n, even if it was a \0
		cursor += d;
	}

	close(fd);
}

int SSL_write(SSL *ssl, const void *buf, int num) {
	int (*old_ssl_write)(SSL *ssl, const void *buf, int num);
	old_ssl_write = dlsym(RTLD_NEXT, "SSL_write");
	log_ssl(SSL_WRITE, (char *) buf, num);
	return old_ssl_write(ssl, buf, num);
}

int SSL_read(SSL *ssl, void *buf, int num) {
	int (*old_ssl_read)(SSL *ssl, const void *buf, int num);
	old_ssl_read = dlsym(RTLD_NEXT, "SSL_read");
	int result = old_ssl_read(ssl, buf, num);
	log_ssl(SSL_READ, (char *) buf, num);
	return result;
}

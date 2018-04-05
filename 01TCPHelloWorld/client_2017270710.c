#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main() {

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		printf("socket error\n");
		exit(1);
	}

	struct sockaddr_in serveraddr;

	memset(&serveraddr, 0, sizeof(struct sockaddr_in));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8080);
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	int err = connect(sockfd, (const struct sockaddr *) &serveraddr, sizeof(serveraddr));

	if (err == -1) {
		printf("connect error\n");
		exit(1);
	}

	char buf[1000];
	memset(buf, 0, 1000);
	strcpy(buf, "World");
	write(sockfd, buf, strlen(buf) + 1);

	int sz = read(sockfd, buf, 1000);
	buf[sz] = '\0';
	printf("%s", buf);

	close(sockfd);
}


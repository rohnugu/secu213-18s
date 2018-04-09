#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int main() {

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		printf("socket error\n");
		exit(1);
	}

	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(struct sockaddr_in));

	union {
		unsigned int addr;
		unsigned char c[4];
	}un;

	un.c[0] = 1;
	un.c[1] = 0;
	un.c[2] = 0;
	un.c[3] = 127;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = un.addr;

	int connfd = connect(sockfd, (const struct sockaddr *) &addr, sizeof(struct sockaddr_in));

	if (connfd == -1) {
		printf("connect error\n");
		exit(1);
	}

	char buf[1000];

	memset(buf, 0, 1000);
	strcpy(buf, "hello");
	write(sockfd, buf, strlen(buf) + 1);

	buf[sz] = "\0";
	printf("%s", buf);

	close(connfd);
}






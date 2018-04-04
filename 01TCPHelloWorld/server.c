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

	if(sockfd == -1) {
		printf("socket error\n");
		exit(1);
	}

	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(struct sockaddr_in));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int err = bind(sockfd, (const struct sockaddr *) &addr, sizeof(struct sockaddr_in));
	if(err == -1) {
		printf("bind error\n");
		exit(-1);
	}

	err = listen(sockfd, 5);
	if(err == -1) {
		printf("listen error\n");
	}

	struct sockaddr clientaddr;
	int szclientaddr;

	int connfd = accept(sockfd, &clientaddr, &szclientaddr);

	close(sockfd);

	char buf[1000];

	int sz = read(connfd, buf, 1000);

	buf[sz] = '\0';

	printf("%s", buf);

	memset(buf, 0, 1000);
	strcpy(buf, "World");

	write(connfd, buf, strlen(buf) + 1);

	close(connfd);
}

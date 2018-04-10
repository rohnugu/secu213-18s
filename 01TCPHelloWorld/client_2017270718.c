#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

void main(){

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd == -1) {
		printf("socket error\n");
		exit(1);
	}

	struct sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(struct sockaddr_in));

	union{
		unsigned int addr;
		unsigned char c[4];
	}un;

	un.c[0] = 1;
	un.c[1] = 0;
	un.c[2] = 0;
	un.c[3] = 127;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	server_addr.sin_port = un;	
//	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	 // if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) 
  //   {
  //       printf("\nInvalid address/ Address not supported \n");
  //       exit(1);
  //   }


	int err = connect(sockfd, (const struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));

	if(err == -1){
		printf("connect error\n");
		exit(1);
	}

	char buf[1000];

	memset(buf, 0, 1000);
	strcpy(buf, "Hello ");
	write(sockfd ,buf, strlen(buf)+1);

	memset(buf, 0 , 1000);
	int sz = read(sockfd, buf, 1000);
	buf[sz] = '\0';
	printf("%s\n", buf);

	close(sockfd);
}
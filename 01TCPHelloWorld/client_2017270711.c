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

        union{
                unsigned int addr;
                unsigned char c[4];
        } un;

        un.c[0]=1;
        un.c[1]=0;
        un.c[2]=0;
        un.c[3]=127;


        addr.sin_family = AF_INET;
        addr.sin_port = htons(8080);
        addr.sin_addr.s_addr = 0;

        int err = connect(sockfd,(struct sockaddr*)&addr, sizeof(struct sockaddr_in));

        if(err == -1) {
                printf("Connection error\n");
                exit(-1);
        }

        char buf[1000];

        memset(buf, 0, 1000);
        strcpy(buf, "Hello ");
        write(sockfd, buf, strlen(buf)+1);

        memset(buf, 0, 1000);

        int sz = read(sockfd, buf, 1000);

        if(sz<0){
                printf("read error\n");
                exit(-1)
        }

        buf[sz] = '\0';

        printf("%s", buf);

        close(sockfd);
}

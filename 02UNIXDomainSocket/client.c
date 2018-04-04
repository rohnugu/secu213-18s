#include <sys/types.h>
#include <sys/socket.h>

main()
{
	int sd, ns;
	char buf[256];
	struct sockaddr sockaddr;
	int fromlen;

	sd = socket(AF_UNIX, SOCK_STREAM, 0);

	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.sa_family = AF_UNIX;
	strncpy(sockaddr.sa_data, "sockname", sizeof("sockname") - 1);

	/* connect to name - null char is not part of name */
	if(connect(sd, &sockaddr, sizeof(sockaddr)) == -1) {
		printf("connect failed\n");
		exit(-1);
	}

	write(sd, "hi guy", 6);
}

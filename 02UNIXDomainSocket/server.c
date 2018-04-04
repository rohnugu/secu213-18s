#include <sys/types.h>
#include <sys/socket.h>

main()
{
	int sd, ns;
	char buf[256];
	struct sockaddr socklisten;
	struct sockaddr sockaddr;
	int fromlen;

	sd = socket(AF_UNIX, SOCK_STREAM, 0);

	memset(&socklisten, 0, sizeof(socklisten));
	socklisten.sa_family = AF_UNIX;
	strncpy(socklisten.sa_data, "sockname", sizeof("sockname") - 1);

	bind(sd, &socklisten, sizeof(socklisten));
	listen(sd, 1);

	for(;;)
	{
		ns = accept(sd, &sockaddr, &fromlen);
		if(fork() == 0)
		{
			/* child */
			close(sd);
			read(ns, buf, sizeof(buf));
			printf("server read '%s'\n", buf);
			exit(0);
		}
		close(ns);
	}
}

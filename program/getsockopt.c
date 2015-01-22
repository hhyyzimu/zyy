#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>

static void bail(const char *on_what)
{
	if(errno != 0)
	{
		fputs(strerror(errno),stderr);
		fputs(":", stderr);
	}
	fputs(on_what, stderr);
	fputc('\n', stderr);

	exit(1);
}

int main(int argc, char **argv)
{
	int z;
	int s = -1; /*Socket*/
	int sndbuf = 0; /*Send buffer size*/
	int rcvbuf = 0; /*Receive buffer size*/
	socklen_t optlen; /*Option length*/

	/*create tcp/ip socket to use*/
	s = socket(PF_INET, SOCK_STREAM, 0);
	if(s == -1)
		bail("socket(2)");

	/*get socket option SO_SNDBUF*/
	//optlen = sizeof sndbuf;
	//z = getsockopt(s, SOL_SOCKET, SO_SNDBUF, &sndbuf, &optlen);
	z = getsockopt(s, SOL_SOCKET, SO_SNDBUF, &sndbuf, &sizeof(sndbuf));

	if(z)
		bail("getsockopt(s, SOL_SOCKET, "SO_SNDBUF")");
	assert(optlen == sizeof sndbuf);

	/*Get socket option SON_RCVBUF*/
	//optlen = sizeof rcvbuf;
	//z = getsockopt(s, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &optlen);
	z = getsockopt(s, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &sizeof(rcvbuf));
	if(z)
		bail("getsockopt(s, SOL_SOCKET, "SO_RCVBUF")");

	assert(optlen == sizeof rcvbuf);

	/*Report the buffer sizes*/
	printf("Socket s: %d\n", s);
	printf("Send buf: %d bytes\n", sndbuf);
	printf("Recv buf: %d bytes\n", rcvbuf);

	close(s);
	return 0;
}

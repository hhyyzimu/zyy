#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

static void bail(const char *on_what)
{
	if(errno != 0)
	{
		fputs(strerror(errno), stderr);
		fputs(":", stderr);
	}

	fputs(on_what, stderr);
	fputc(' ', stderr);

	exit(1);
}

int main(int argc, char **argv)
{
	int z;
	char *ser_addr = NULL;
	char *ser_port = "9099";
	struct sockaddr_in seraddr, cliaddr;
	socklen_t len_inet;
	int s, c, n;
	time_t td;
	char dtbuf[128];
	FILE *logf;
	struct hostent *hp;

	if(!(logf = fopen("srvr2.log", "w")))
		bail("fopen(3)");

	if(argc >= 2)
	{
		seraddr = argv[1];
	}else
	{
		seraddr = "127.0.0.1";
	}

	if(argc >= 3)
		ser_port = argv[2];

	s = socket(PF_INET, SOCK_STREAM, 0);
	if(s = -1)
	{
		bail("socket()");
	}

	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(ser_port));
	if(strcmp(ser_addr, "*") != 0)
	{
		seraddr.sin_addr.s_addr = inet_addr(ser_addr);
		if(seraddr.sin_addr.s_addr == INADDR_NONE)
			bail("bad address");
	}else
	{
		seraddr.sin_addr.s_addr = INADDR_ANY;
	}

	len_inet = sizeof(seraddr);
	z = bind(s, (struct sockaddr *)&seraddr, len_inet);
	if(-1 == z)
		bail("bind()");

	z = listen(s, 10);
	if(z == -1)
		bail("listen()");

	for(;;)
	{
		len_inet = sizeof(cliaddr);
		c = accept(s, (struct sockaddr *)&cliaddr, &len_inet);
		if(c == -1)
			bail("accept()");

		fprintf(logf, "Client %s:", inet_ntoa(cliaddr.sin_addr));

		hp = gethostbyaddr((char *)&cliaddr.sin_addr, sizeof(cliaddr), cliaddr.sin_family);
		if(!hp)
			fprintf(logf, "Error: %s", hstrerror(h_errno));
		else
			fprintf(logf, "%s", hp->h_name);

		fflush(logf);

		time(&td);
		n = (int)strftime(dtbuf, sizeof(dtbuf), "%A %b %d %H:%M:%S %Y", localtime(&td));
		z= write(c, dtbuf, n);
		if(z == -1)
			bail("write()");

		close(c);
	}
	return 0;
}

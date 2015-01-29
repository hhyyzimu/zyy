#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sevfd;

	if((sevfd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stdout, "socket error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	int ret;
	struct sockaddr_un sevaddr;
	sevaddr.sun_family = AF_LOCAL;
	
	bcopy("/tmp/unix_tmp", sevaddr.sun_path, sizeof("/tmp/unix_tmp"));
	if((ret = connect(sevfd, (struct sockaddr *)&sevaddr, sizeof(sevaddr))) < 0)
	{
		fprintf(stdout, "connect error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	char sbuf[1024], rbuf[1024];
	int i;
	for(i = 0; i < 10; i++)
	{
		bzero(sbuf, sizeof(sbuf));
		sbuf[0] = '0' + i;
		send(sevfd, sbuf, sizeof(sbuf), 0);
		fprintf(stdout, "sbuf: %s\n", sbuf);

		bzero(rbuf, sizeof(rbuf));
tryagain:
		if((ret = recv(sevfd, rbuf, sizeof(sbuf), MSG_DONTWAIT)) > 0)
		{
			fprintf(stdout, "rbuf: %s\n", sbuf);
		}
		else if(ret == 0)
		{
			fprintf(stdout, "peer close\n");
			close(sevfd);
			sevfd = -1;
			exit(EXIT_FAILURE);
		}
		else if(errno == EAGAIN)
		{
			fprintf(stdout, "try again\n");
			sleep(1);
			goto tryagain;
		}
		else
		{
			fprintf(stdout, "received error: %s\n", strerror(errno));
			close(sevfd);
			sevfd = -1;
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "rbuf: %s\n", rbuf);
	}
	return 0;
}

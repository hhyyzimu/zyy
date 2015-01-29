//运行：./a.out www.163.com
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

extern int h_errno;

int main(int argc, char *argv[])
{
	int i, j;
	struct hostent *ent;

	for(i=1; i<argc; ++i)
	{
		ent = gethostbyname(argv[i]);
		if(!ent)
		{
			fprintf(stderr, "%s: host %s", hstrerror(h_errno), argv[i]);
			continue;
		}

		printf("Host %s:", argv[i]);
		printf("Officially: %s", ent->h_name);
		fputs("tAliases: ", stdout);
		for(j=0; ent->h_aliases[j]; j++)
		{
			if(j)
				fputs(",", stdout);
			fputs(ent->h_aliases[j], stdout);
		}

		fputc(' ', stdout);
		printf("Type: %s", ent->h_addrtype == AF_INET ? "AF_INET":"AF_INET6");
		if(ent->h_addrtype == AF_INET)
		{
			for(j=0; ent->h_addr_list[j]; ++j)
			{
				printf("Address: %s", inet_ntoa(*(struct in_addr *)ent->h_addr_list[j]));
			}
		}
		putchar(' ');
	}

	return 0;
}

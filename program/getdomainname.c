#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int name;
	char buf[32];

	name = gethostname(buf, sizeof(buf));
	if(name == -1)
	{
		fprintf(stderr, "%s: gethostname()\n", strerror(errno));
		exit(1);
	}
	printf("host name = %s\n", buf);

	name = getdomainname(buf, sizeof(buf));
	if(name == -1)
	{
		fprintf(stderr, "%s: getdomainname()\n", strerror(errno));
		exit(1);
	}
	printf("domain name = %s\n", buf);
}

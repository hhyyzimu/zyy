#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int name;
	struct utsname u_name;

	name = uname(&u_name);
	if(name == -1)
	{
		fprintf(stderr, "%s, uname()", strerror(errno));
		exit(1);
	}

	printf("sysname[] = %s\n", u_name.sysname);
	printf("nodename[] = %s\n", u_name.nodename);
	printf("release[] = %s\n", u_name.release);
	printf("version[] = %s\n", u_name.version);
	printf("machine[] = %s\n", u_name.machine);
	printf("domainname[] = %s\n", u_name.__domainname);//在ubuntu中要用__domainname,可参考sys/utsname.h
}

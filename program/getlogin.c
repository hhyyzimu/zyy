#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	uid_t uid;
	gid_t gid;

	uid = getuid();
	printf("User is %s\n", getlogin());
	printf("User IDs: uid = %d\n", uid);

	exit(0);
}

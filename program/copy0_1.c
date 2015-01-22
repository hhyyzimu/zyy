#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int n;
	char buf[BUFSIZ];

	while((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			perror("write()");
	if(n < 0)
		perror("read()");

	exit(0);
}

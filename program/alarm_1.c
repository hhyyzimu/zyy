#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int ret = 0;

	ret = alarm((unsigned int)argv[1]);

	ret = alarm(10);
	fprintf(stdout, "ret : %d\n", ret);

	sleep(3);
	ret = alarm(10);
	fprintf(stdout, "ret : %d\n", ret);

	ret = alarm(1);
	fprintf(stdout, "ret : %d\n", ret);
}

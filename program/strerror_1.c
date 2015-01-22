#include <stdio.h>
#include <stdlib.h>

#define	N	100

int main()
{
	int n;

	for(n=0; n<N; n++)
	{
		fputs(strerror(n), stderr);
		printf("\n");
		n++;
	}

	exit(0);
}

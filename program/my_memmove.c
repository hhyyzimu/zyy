#include <stdio.h>
#include <stdlib.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
	char temp[n];
	int i;
	char *d = dest;
	const char *s = src;

	for(i=0; i<n; i++)
	{
		temp[i] = (char)src[i];
	}
	for(i=0; i<n; i++)
	{
		d[i] = temp[i];
	}

	return dest;
}

int main()
{
	char *src = "hello world!";
	char *dest;
	int n = 3;

	my_memmove(dest, src, n);

	printf("dest = %s\n", dest);

	exit(0);
}

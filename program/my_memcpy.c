#include <stdio.h>
#include <string.h>
#include <assert.h>

void *my_memcpy(void *dest, const void *src, size_t count)
{
	assert(dest != NULL && src != NULL);
	char *tmp = dest;
	const char *s = src;
	int i;

	for(i = 0; i < count; i++)
	{
		tmp[i] = s[i];
	}
	return dest;
}

int main()
{
	char *s = "Go to luckily";
	char d[20];
	
	system("clear");
	my_memcpy(d, s, (strlen(s) + 1));
	printf("%s", d);
	getchar();
	
	return 0;
}

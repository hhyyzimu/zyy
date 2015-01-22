#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str = NULL;

	str = (char *)calloc(10, sizeof(char));
	strcpy(str, "Hello");
	printf("String is: %s\n", str);

	free(str);

	exit(0);
}

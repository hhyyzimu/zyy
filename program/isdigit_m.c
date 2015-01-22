#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char str[] = "123@#FDsP[e?";
	int i;
	
	for(i = 0; str[i] != 0; i++)
	{
		if(isdigit(str[i]))
		printf("%c is an digit character\n", str[i]);
	}

	exit(0);
}

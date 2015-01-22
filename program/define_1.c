#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define NAME(str1,str2...)  printf(str1, ##str2, ##__VA_ARGS__)
#define NAME(str1,str2...)  printf(str1, ##str2)

int main()
{
	NAME(ZYY, I, LOVE, YOU);

	exit(0);
}

#include <stdio.h>

void main()
{
	union number
	{
		int i;
		char j;
		struct
		{
			char first;
			char second;
		}half;
	}num;

	num.j = 'j';
	num.i = 0x4241;
	num.half.second = 'b';
	printf("%c %c\n", num.half.first, num.half.second);
	num.half.second = 'b';
	printf("%x\n", num.i);
//	printf("%c\n", num.j);

	getchar();
}

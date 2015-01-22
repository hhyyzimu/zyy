/*在字符串中找出连续最长的数字串，把串的长度返回，并把最长数字传赋给函数参数outputstr所指内存*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findnumstring(char *outputstr, char *inputstr)
{
	char *in = inputstr, *out = outputstr, *temp, *final;
	int count = 0, maxlen = 0, i = 0;

	while(*in != '\0')
	{
		if(*in>47 && *in<58)
		{
			for(temp = in; *in > 47 && *in < 58; in++ )
				count++;
		}
		else
			in++;

		if(maxlen < count)
		{
			maxlen = count;
			final = temp;
		}
		count = 0;
	}

	for(i = 0; i < maxlen; i++)
	{
		*out = *final;
		out++;
		final++;
	}
	*out = '\0';
	
	return maxlen;
}

int main()
{
	char string[] = "abcd12345eee123ss123456789";
	char *p = (char *)malloc(strlen(string)+1);
	int count = findnumstring(p, string);
	printf("%s\nnumber string length = %d\n", p, count);

	exit(0);
}

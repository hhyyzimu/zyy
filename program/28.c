/*在一个长串中找一个短串，如果有，输出提示语句和短串在长串中的其实位置*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_str(char *str1,char *str2)
{
	int i,j,k;
	k = strlen(str2);
	for(i = 0;str1[i] != '\0';i++)
	{
		if(str1[i] == str2[0])
		{
			for(j = 0;j < k;j++)
			{
				if(str1[i+j] != str2[j])
				{
					break;
				}
			}
		if(j == k)
		{
			printf("str2 first display at %d\n",i+1);
		}
		else
		{
			printf("no find str2\n");
		}
		}
	}
}

int main()
{
	char str1[100],str2[10];
	printf("input string str1:\n");
	gets(str1);
	printf("input the finding string str2:\n");
	gets(str2);
	find_str(str1,str2);

	exit(0);
}

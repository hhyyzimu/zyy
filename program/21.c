/*
 *计算简单的四则运算，只要求支持两个整数运算，格式为：
 * $./a.out		14+3
 *17
 * */
#include <stdio.h>

int main(int argc,char *argv[])
{
	char *s=argv[1];
	int v1=0,v2=0;
	char oper;
	while(*s)
	{
		if(*s=='0'||*s=='1'||*s=='2'||*s=='3'||*s=='4'||*s=='5'||*s=='6'||*s=='7'||*s=='8'||*s=='9')
		{
			v1=v1*10+*s-'0';
		}
		else
		{
			v2=v1;
			v1=0;
			oper=*s;
			}
			s++;
	}
	switch(oper)
	{
		case '+':
			printf("%d\n",v2+v1);
			break;
		case '-':
			printf("%d\n",v2-v1);
			break;
		case '*':
			printf("%d\n",v2*v1);
			break;
		case '/':
			printf("%d\n",v2/v1);
			break;
		}

	return 0;
	}

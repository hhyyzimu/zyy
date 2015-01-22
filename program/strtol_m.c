/*
strtol函数会将参数nptr字符串根据参数base来转换成长整型数。
long int strtol(const char *nptr,char **endptr,int base);
参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制等。当base值为0时则是采用10进制做转换，但遇到如’0x’前置字符则会使用16进制做转换、遇到’0’前置字符而不是’0x’的时候会使用8进制做转换。
一开始strtol()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回；若参数endptr为NULL，则会不返回非法字符串。

double strtod(const char *nptr, char **endptr);
扫描参数nptr字符串，跳过前面的空格字符，知道遇上数字或正负号才开始做转换，到出现非数字或字符串结束时（'\0'）才结束转换，并将结果返回。若endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr传回，参数nptr字符串可包含正负号、小数点或E（e）来表示指数部分。如123.456或123e-2.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *string, *stopstring;
	double x;
	int base;
	long l;
	unsigned long ul;

	string = "3.1415926Thisstoppedit";
	x = strtod(string, &stopstring);
	printf("string = %s\n", string);
	printf("strtod = %f\n", x);
	printf("Stopped scanat:%s\n", stopstring);
	printf("\n");
	
	string = "-1022223332Thisstoppedit";
	l = strtol(string, &stopstring, 4);
	printf("string=%s\n", string);
	printf("strtol=%ld\n", l);
	printf("Stoppedscanat:%s\n", stopstring);
	printf("\n");

	string = "10110134932";
	printf("string = %s\n", string);
	printf("\n");

	for(base = 2; base <= 8; base *= 2)
	{
		ul = strtoul(string, &stopstring, base);
		printf("strtoul = %ld(base%d)\n", ul, base);
		printf("Stoppedscanat:%s\n", stopstring);
	}

	exit(0);
}

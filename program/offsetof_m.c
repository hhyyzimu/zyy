#include <stdio.h>
#include <stddef.h>

typedef struct
{
	int iVal;
	int iVal2;
}Test;

typedef struct
{
	char ch;
	double ch2;
	double ch3;
	char ch4;
	int iNum;
}Test2;

int main(void)
{
	Test t = {1,2};	
	Test2 t2 = {'t',100};
	printf("address of t:%p\n\
		address of t.iVal:%p\n\
		address of t.iVal2:%p\n",\
		&t, &(t.iVal), &(t.iVal2));

	printf("offset of iVal in t:%d\n",offsetof(Test,iVal));
	printf("offset of iVal2 in t:%d\n",offsetof(Test,iVal2));

	printf("address of t2:%p\n\
		address of t2.ch:%p\n\
		address of t2.iNum:%p\n",\
		&t2, &(t2.ch), &(t2.iNum));

	printf("offset of iVa2 int t:%d\n",offsetof(Test2,ch));
	printf("offset of iVa2 iNum t:%d\n",offsetof(Test2,iNum));

	printf("sizeof(Test) = %d\n",sizeof(Test));
	printf("sizeof(Test2) = %d\n",sizeof(Test2));
	printf("sizeof(double) = %d\n",sizeof(double));
}

#include <stdio.h>
#include <stdlib.h>

int add(int i)
{	
	int sum;
	if(i > 0 && i <= 5)
	{
		sum = i + add(i-1);
	}else{
		sum = 0;//可以说在这给sum赋的初值，如果不写此不，sum的初值将是乱码，也不能在开始给sum赋初值，这样，没执行一次此函数，sum都会被初始化成一个固定的数
	}
	
	return sum;
}

int main()
{
	int i = 5;
	int sum = 0;
	sum = add(i);
	
	printf("sum = %d\n", sum);

	exit(0);
}

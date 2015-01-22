#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	alarm(50);
	
	int ret;
	
	sleep(30);
	ret = alarm(10);//返回上一个闹钟的剩余时间
	printf("%d\n", ret);

	sleep(1);
	ret = alarm(5);

	printf("%d\n", ret);

	pause();

	return 0;
}

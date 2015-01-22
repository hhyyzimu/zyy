/*
计算一秒钟会有多少个始终计时单元
#define CLOCKS_PER_SEC ((clock_t)1000)

计算一个进程自身的运行时间
void elapsed_time()
{
	printf("Elapsed time:%u secs.\n", clock()/CLOCKS_PER_SEC);
}

*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	long i = 10000000L;
	clock_t start, finish;
	double duration;

	/*测量一个事件持续的时间*/
	printf("Time to do %ld empty loops is ", i);
	start = clock();
	while(i--);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
}

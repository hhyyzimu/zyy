#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/klog.h>
#include <syslog.h>

int main()
{
	struct timeval tv1, tv2;
	
	gettimeofday(&tv1, NULL);
	
	syslog(LOG_INFO, "function:%s, line:%d, time:%s \n", __func__, __LINE__, __TIME__);

	sleep(2);
	
	gettimeofday(&tv2, NULL);
	
	printf("time_func:%ld.%ld\n",tv2.tv_sec - tv1.tv_sec, tv2.tv_usec - tv1.tv_usec);
	
	syslog(LOG_INFO, "function:%s, line:%d, time:%s, maxtime:%ld.%ld\n", __func__, __LINE__, __TIME__, tv2.tv_sec - tv1.tv_sec, tv2.tv_usec - tv1.tv_usec);

	exit(0);
}

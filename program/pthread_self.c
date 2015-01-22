//gcc pthread_self -lpthread 
#include <stdio.h>
#include <pthread.h>

int main()
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("pid=%u\ntid=%u (0x%x)\n", (unsigned int)pid, (unsigned long int)tid, (unsigned long int)tid);

	return 0;
}

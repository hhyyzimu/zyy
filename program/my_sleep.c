#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_alrm(int signo){}

unsigned int mysleep(unsigned int nsecs)
{
	struct sigaction newact, oldact;
	unsigned int unslept;

	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	sigaction(SIGALRM, &newact, &oldact);

	alarm(nsecs);
	pause();
	
//	printf("zyy\n");
//	printf("func:%s,line:%d\n",__func__, __LINE__);
	unslept = alarm(0);
//	printf("unslept:%d\n", unslept);
	sigaction(SIGALRM, &oldact, NULL);

	return unslept;
}

int main()
{
	while(2){
		mysleep(2);
		printf("Two seconds passed\n");
	printf("zyy\n");
//	printf("func:%s,line:%d\n",__func__, __LINE__);
	}
	
	exit(0);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){ //first child
		if((pid = fork()) < 0){
			perror("fork()");
			exit(2);
		}else if(pid > 0)
			exit(0); //parent from second fork == first child

		/*
		 we are the second child;
		 */
		sleep(2);
		printf("second child, parent pid = %d\n", getppid());
		exit(0);
	}

	if(waitpid(pid, NULL, 0) != pid){ //wait for first child
		printf("waitpid error");
		exit(3);
	}

	printf("first pid = %d\n", pid);

	/*
	 we are the parent;
	 */
	exit(0);
}

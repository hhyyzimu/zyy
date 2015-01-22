#include <stdio.h>
#include <stdlib.h>

void my_listen(int fd, int backlog)
{
	char *ptr;
	
	if((ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);		
	if(listen(fd, backlog) < 0)
		printf("listen error");
}

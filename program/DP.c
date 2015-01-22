#include <stdio.h>
#include <stdlib.h>

#define DP(fmt, args...) \
	printf(fmt, ##args)

int main()
{
	char *msg = NULL;

	msg = malloc(sizeof(msg));

	printf("Please input the message: ");
	//scanf("%s", &msg);
	
	fgets(msg, 100, stdin);
	DP("msg: %s\n", msg);
	DP("msg\n");

	exit(0);
}

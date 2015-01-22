#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void int_handler(int s)
{
	printf("Catch a signal sigint\n");
}

int main()
{
	exit(0);
}

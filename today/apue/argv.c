#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;

	if(argc < 2){
		printf("Usage:%s message\n", argv[0]);
		exit(1);
	}else{
		for(i = 1; i <= argc; i++)
		{
			system(argv[i]);
		}
	}

	exit(0);
}

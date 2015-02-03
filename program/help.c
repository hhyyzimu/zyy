/*./a.out -h*/
#include <stdio.h>
#include <stdlib.h>

static void usage(void)
{
	fprintf(stderr, "\n Usage:\n");
	fprintf(stderr, "\n \t-s: Show vserver && topology information.\n");
	fprintf(stderr, "\n \t-t: Show topology information.\n");
	fprintf(stderr, "\n \t-v: Show vserver information.\n");
	fprintf(stderr, "\n \t-c: Cleanup connections.\n");
	fprintf(stderr, "\n \t-b: Resync connection table.\n");
	fprintf(stderr, "\n \t-l: Show local adresses.\n");
}

int main(int argc, char **argv)
{
	int c;

	if((c = getopt(argc, argv, "sctvhbknlm")) != -1)
	{
		switch(c){
			case 'h':
				usage();
				break;
		}
	}
	
	exit(0);
}

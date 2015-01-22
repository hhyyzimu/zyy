#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

#define TOK_ADD	-1
#define MAXLINE	1024

jmp_buf jmpbuffer;

#if 1
int get_token(void)
{
	return TOK_ADD;
}
#endif

void do_line(const char *ch)
{
	printf(ch);
}

int main()
{
	char line[MAXLINE];

	if(setjmp(jmpbuffer) != 0)
		printf("error");

	while(fgets(line, MAXLINE, stdin) != NULL)
		do_line(line);

	exit(0);
}



void cmd_add(void)
{
	int token;

	token = get_token();
		printf("zzzzzzzzz");
	if(token < 0)
	{
		longjmp(jmpbuffer, 1);
	}
}

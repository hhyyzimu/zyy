#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	umask(0);//不屏蔽任何权限
	if(creat("a.test", S_IRWXU|S_IRWXG|S_IRWXO) < 0){
		perror("creat()");
		exit(1);
	}
	printf("creat a.test OK!\n");

	umask(S_IRWXO);//屏蔽其他用户的所有权限
	if(creat("b.test", S_IRWXU|S_IRWXG|S_IRWXO) < 0){
		perror("creat()");
		exit(1);
	}
	printf("creat b.test OK!\n");

	exit(0);
}

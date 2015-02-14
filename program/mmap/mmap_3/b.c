#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>

#define BUF_SIZE	100

int main(int argc, char **argv)
{
	int fd, nread, i;
	struct stat sb;
	char *mapped, buf[BUF_SIZE];

	for(i = 0; i < BUF_SIZE; i++){
		buf[i] = '#';
	}

	/*打开文件*/
	if((fd = open(argv[1], O_RDWR)) < 0){
		perror("open");
	}

	/*获取文件的属性*/
	if((fstat(fd, &sb)) == -1){
		perror("fstat");
	}

	if((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1){
		perror("mmap");
	}

	/*映射完后，关闭文件也可以操纵内存*/
	close(fd);

	/*修改一个字符*/
	mapped[20] = '9';

	return 0;
}

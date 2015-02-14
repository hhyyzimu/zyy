/*./map_normalfile1 a;
 * 同时
 * ./map_normalfile2 a
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

typedef struct { //共享内存区的数据往往是有固定格式的
	char name[4];
	int age;
}people;

void main(int argc, char **argv) //map a normal file as shared mem
{
	int fd, i;
	people *p_map;
	char temp;

	fd = open(argv[1], O_CREAT|O_RDWR|O_TRUNC, 00777); //打开或创建一个一个文件，并把文件长度设置为5各people结构大小
	lseek(fd,sizeof(people)*5-1, SEEK_SET);
	write(fd, " ", 1);
	p_map = (people *)mmap(NULL, sizeof(people)*10, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	temp = 'a';
	for(i=0; i<10; i++){
		temp += 1;
		memcpy((*(p_map+i)).name, &temp, 2);
		(*(p_map+i)).age = 20+i;
	}
	printf("init ialize over\n");
	sleep(10); //随眠10分钟，等待其他进程映射同一个文件
	munmap(p_map, sizeof(people)*10);
	printf("munmap ok\n");

}

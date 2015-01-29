#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>

#define SIZE	1024

int main()
{
	int shmid;
	char *shmaddr;
	struct shmid_ds buf;
	int flag = 0;
	int pid; 

	shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0600);//父子进程用IPC_PRIVATE代替
	if(shmid < 0)
	{
		perror("get shm ipc_id error");
		return -1;
	}

	pid = fork();
	if(pid == 0)
	{
		shmaddr = (char *)shmat(shmid, NULL, 0);//由内核把共享内存映像到调用进程的地址空间中选定位置
		if((int)shmaddr == -1)
		{
			perror("shmat addr error");
			return -1;
		}

		strcpy(shmaddr, "Hi, i am child process!\n");//向共享内存中写入数据
		shmdt(shmaddr);//删除进程对这块共享内存的"使用"

		return 0;
	}else if(pid > 0){//父进程
		sleep(3);

		flag = shmctl(shmid, IPC_STAT, &buf);//父进程获取共享内存的状态，存入buf
		if(flag == -1)
		{
			perror("shmctl shm error!");
			return -1;
		}

		printf("is in parent-->shm_segsz = %d bytes\n", buf.shm_segsz);
		printf("is in parent-->parent pid = %d, shm_cpid = %d\n", getpid(), buf.shm_cpid);
		printf("is in parent-->child pid = %d, shm_lpid = %d\n", pid, buf.shm_lpid);

		printf("is in parent-->i will shmat in parent and use the kernel made!\n");
		shmaddr = (char *)shmat(shmid, NULL, 0);//由内核映射一个共享内存
		if((int)shmaddr == -1)
		{
			perror("shmat addr error");
			return -1;
		}
		printf("is in parent-->%s", shmaddr);
		shmdt(shmaddr);//删除本进程对这快共享内存的使用
		shmctl(shmid, IPC_RMID, NULL);//删除共享内存
	}else{//创建进程失败
		perror("fork error");
		shmctl(shmid, IPC_RMID, NULL);
	}

	return 0;
}

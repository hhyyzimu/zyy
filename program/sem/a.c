#include <stdio.h>

static int nsems;
static int semflg;
static int semid;

int errno = 0;

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
}arg;

int main()
{
	struct sembuf sops[2]; //要用到两个信号量
	int rslt;
	unsigned short argarray[80];
	
	arg.array = argarray;
	semid = semget(IPC_PRIVATE, 2, 0666);
	if(semid < 0)
	{
		printf("semget failed. errno: %d\n", errno);
		exit(1);
	}

	//获得0th信号两的原始值
	rslt = semctl(semid, 0, GETVAL);
	printf("val = %d\n", rslt);

	//初始化0th信号量，然后再读取，检查初始化有没有成功
	arg.val = 1; //同一时间之允许一个占有者
	semctl(semid, 0, SETVAL, arg);
	rslt = semctl(semid, 0, GETVAL);
	printf("var = %d\n", rslt);
	sops[0].sem_num = 0;
	sops[0].sem_op = -1;
	sops[0].sem_flg = 0;
	sops[1].sem_num = 1;
	sops[1].sem_op = 1;
	sops[1].sem_flg = 0;
	rslt = semop(semid, sops, 1); //申请0th信号量，尝试锁定
}
